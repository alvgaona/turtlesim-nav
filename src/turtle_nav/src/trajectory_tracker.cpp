#include "trajectory_tracker.h"

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
    k_() {
  Q_ = casadi::MX(options.Q);
  R_ = casadi::MX(options.R);

  x_ = opti_.variable(num_states_, N_ + 1);
  u_ = opti_.variable(num_inputs_, N_);
  x0_ = opti_.parameter(num_states_);
  r_ = opti_.parameter(num_states_, N_ + 1);

  init();
}

void TrajectoryTracker::init() {
  casadi::MX J = 0;  // objective function

  for (int k = 0; k < N_; k++) {
    auto state_error = x_(casadi::Slice(), k) - r_(casadi::Slice(), k);

    J +=
      casadi::MX::mtimes(casadi::MX::mtimes(state_error.T(), Q_), state_error);
    J += casadi::MX::mtimes(
      casadi::MX::mtimes(u_(casadi::Slice(), k).T(), R_), u_(casadi::Slice(), k)
    );

    auto x_k = x_(casadi::Slice(), k);
    auto u_k = u_(casadi::Slice(), k);

    // Euler integration
    auto x_next = x_k + unicycle_kinematics(x_k, u_k) * dt_;

    opti_.subject_to(x_(casadi::Slice(), k + 1) == x_next);
  }

  auto final_state_error = x_(casadi::Slice(), N_) - r_(casadi::Slice(), N_);
  J += casadi::MX::mtimes(
    casadi::MX::mtimes(final_state_error.T(), Q_), final_state_error
  );

  opti_.minimize(J);
  opti_.subject_to(x_(casadi::Slice(), 0) == x0_);
  opti_.subject_to(u_(0, casadi::Slice()) >= 0);
  opti_.subject_to(u_(0, casadi::Slice()) <= 5);
  opti_.subject_to(u_(1, casadi::Slice()) >= -1);
  opti_.subject_to(u_(1, casadi::Slice()) <= 1);
  opti_.subject_to(x_(0, casadi::Slice()) >= 0);
  opti_.subject_to(x_(0, casadi::Slice()) <= 10);
  opti_.subject_to(x_(1, casadi::Slice()) >= 0);
  opti_.subject_to(x_(1, casadi::Slice()) <= 10);

  opti_.solver(
    "ipopt",
    {
      {"expand", true},
    },
    {
      {"max_iter", 1000},
      {"print_level", 0},
      {"acceptable_tol", 1e-8},
      {"acceptable_obj_change_tol", 1e-6},
    }
  );
}

casadi::DM TrajectoryTracker::step(const casadi::DM& x) {
  int m = static_cast<int>(ref_traj_.size2());
  casadi::Slice cols(std::min(k_, m - 1), std::min(N_ + 1 + k_, m));
  casadi::DM ref = ref_traj_(casadi::Slice(), cols);

  if (ref.size2() < N_ + 1) {
    int padding = N_ + 1 - static_cast<int>(ref.size2());
    ref = pad(ref, padding, 0);
  }

  opti_.set_value(r_, ref);
  opti_.set_value(x0_, x);
  const auto sol = opti_.solve();
  k_++;
  return sol.value(u_);
}
