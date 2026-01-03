#include "trajectory_tracker.h"

#include <cmath>
#include <limits>
#include <tinysplinecxx.h>

#include <casadi/casadi.hpp>
#include <casadi/core/dm_fwd.hpp>
#include <casadi/core/optistack.hpp>
#include <casadi/core/slice.hpp>

#include "kinematics.h"

TrajectoryTracker::TrajectoryTracker(const Options& options)
  : N_(options.horizon_length),
    num_states_(options.state_dim),
    num_inputs_(options.input_dim),
    dt_(options.dt),
    v_weight_(options.v_weight),
    k_(0),
    last_u_(casadi::DM::zeros(options.input_dim, options.horizon_length)) {
  Q_ = casadi::MX(options.Q);
  R_ = casadi::MX(options.R);

  x_ = opti_.variable(num_states_, N_ + 1);
  u_ = opti_.variable(num_inputs_, N_);
  x0_ = opti_.parameter(num_states_);
  r_ = opti_.parameter(num_states_, N_ + 1);
  v_ref_ = opti_.parameter();  // Scalar velocity reference

  init();
}

void TrajectoryTracker::init() {
  casadi::MX J = 0;  // objective function

  for (int k = 0; k < N_; k++) {
    // Track states: [x, y, θ]
    auto state_error = x_(casadi::Slice(), k) - r_(casadi::Slice(), k);

    J +=
      casadi::MX::mtimes(casadi::MX::mtimes(state_error.T(), Q_), state_error);
    J += casadi::MX::mtimes(
      casadi::MX::mtimes(u_(casadi::Slice(), k).T(), R_), u_(casadi::Slice(), k)
    );

    // Velocity tracking cost: penalize deviation from v_ref
    auto v_error = u_(0, k) - v_ref_;
    J += v_weight_ * v_error * v_error;

    auto x_k = x_(casadi::Slice(), k);
    auto u_k = u_(casadi::Slice(), k);

    // Euler integration with unicycle kinematics
    auto x_next = x_k + unicycle_kinematics(x_k, u_k) * dt_;

    opti_.subject_to(x_(casadi::Slice(), k + 1) == x_next);
  }

  // Terminal cost (use same Q weights)
  auto final_state_error = x_(casadi::Slice(), N_) - r_(casadi::Slice(), N_);
  J += casadi::MX::mtimes(
    casadi::MX::mtimes(final_state_error.T(), Q_), final_state_error
  );

  opti_.minimize(J);
  opti_.subject_to(x_(casadi::Slice(), 0) == x0_);

  // Input constraints: v (linear velocity), ω (angular velocity)
  opti_.subject_to(u_(0, casadi::Slice()) >= 0);    // min linear velocity
  opti_.subject_to(u_(0, casadi::Slice()) <= 1.0);  // max linear velocity
  opti_.subject_to(u_(1, casadi::Slice()) >= -2.0); // min angular velocity
  opti_.subject_to(u_(1, casadi::Slice()) <= 2.0);  // max angular velocity

  opti_.solver(
    "ipopt",
    {
      {"expand", true},
    },
    {
      {"max_iter", 100},
      {"print_level", 0},
      {"acceptable_tol", 1e-6},
      {"acceptable_obj_change_tol", 1e-6},
      {"warm_start_init_point", "yes"},
    }
  );
}

casadi::DM TrajectoryTracker::step(const casadi::DM& x) {
  int m = static_cast<int>(ref_traj_.size2());

  // Forward-gated path progression
  constexpr double waypoint_threshold = 0.1;  // Advance when within this distance [m]
  constexpr int search_window = 200;          // Max points to search ahead
  constexpr double lookahead_dist = 0.3;      // Track at least this far ahead [m]

  double robot_x = static_cast<double>(x(0));
  double robot_y = static_cast<double>(x(1));

  // 1. Find closest point within search window
  int end_idx = std::min(k_ + search_window, m - 1);
  double min_dist = std::numeric_limits<double>::max();
  int closest_idx = k_;

  for (int i = k_; i <= end_idx; i++) {
    double dx = static_cast<double>(ref_traj_(0, i)) - robot_x;
    double dy = static_cast<double>(ref_traj_(1, i)) - robot_y;
    double dist = std::sqrt(dx * dx + dy * dy);
    if (dist < min_dist) {
      min_dist = dist;
      closest_idx = i;
    }
  }
  k_ = closest_idx;

  // 2. Advance while robot is within waypoint_threshold
  while (k_ < m - 1) {
    double dx = static_cast<double>(ref_traj_(0, k_)) - robot_x;
    double dy = static_cast<double>(ref_traj_(1, k_)) - robot_y;
    double dist = std::sqrt(dx * dx + dy * dy);
    if (dist >= waypoint_threshold) break;
    k_++;
  }

  // 3. Add lookahead distance
  int track_idx = k_;
  double accumulated_dist = 0.0;
  while (track_idx < m - 1 && accumulated_dist < lookahead_dist) {
    double dx = static_cast<double>(ref_traj_(0, track_idx + 1)) -
                static_cast<double>(ref_traj_(0, track_idx));
    double dy = static_cast<double>(ref_traj_(1, track_idx + 1)) -
                static_cast<double>(ref_traj_(1, track_idx));
    accumulated_dist += std::sqrt(dx * dx + dy * dy);
    track_idx++;
  }

  // Extract reference from track_idx
  casadi::Slice cols(std::min(track_idx, m - 1), std::min(N_ + 1 + track_idx, m));
  casadi::DM ref = ref_traj_(casadi::Slice(), cols);

  if (ref.size2() < N_ + 1) {
    int padding = N_ + 1 - static_cast<int>(ref.size2());
    ref = pad(ref, padding, 0);
  }

  // Unwrap current heading to match reference (avoid large errors at ±π boundary)
  casadi::DM x_unwrapped = x;
  double ref_theta = static_cast<double>(ref(2, 0));
  double curr_theta = static_cast<double>(x(2));
  double diff = curr_theta - ref_theta;
  while (diff > M_PI) diff -= 2 * M_PI;
  while (diff < -M_PI) diff += 2 * M_PI;
  x_unwrapped(2) = ref_theta + diff;

  // Compute velocity reference with slowdown near goal
  int last_idx = m - 1;
  double goal_x = static_cast<double>(ref_traj_(0, last_idx));
  double goal_y = static_cast<double>(ref_traj_(1, last_idx));
  double dist_to_goal = std::sqrt(
    (robot_x - goal_x) * (robot_x - goal_x) +
    (robot_y - goal_y) * (robot_y - goal_y)
  );

  // Linear slowdown within slowdown_dist of goal, ramp to 0
  constexpr double slowdown_dist = 1.0;
  double v_ref = average_speed_;
  if (dist_to_goal < slowdown_dist) {
    v_ref = average_speed_ * (dist_to_goal / slowdown_dist);
  }

  opti_.set_value(r_, ref);
  opti_.set_value(x0_, x_unwrapped);
  opti_.set_value(v_ref_, v_ref);

  // Warm-start with last solution
  opti_.set_initial(u_, last_u_);

  const auto sol = opti_.solve();
  last_u_ = sol.value(u_);
  
  return last_u_;
}
