#pragma once

#include <casadi/casadi.hpp>
#include <cmath>
#include <cstdint>
#include <rerun.hpp>
#include <utility>
#include <vector>

#include "utils.h"

class TrajectoryTracker {
 public:
  struct Options {
    int horizon_length;
    int state_dim;
    int input_dim;
    double dt;
    casadi::DM Q;
    casadi::DM R;
    double v_weight = 10000.0;  // Weight for velocity tracking
  };

  TrajectoryTracker() = default;
  explicit TrajectoryTracker(const Options& options);
  ~TrajectoryTracker() = default;

  void init();

  casadi::DM step(const casadi::DM& x);

  void reset() {
    k_ = 0;
    last_u_ = casadi::DM::zeros(num_inputs_, N_);
  }

  void set_target(const casadi::DM& r) { opti_.set_value(r_, r); }

  void set_v_ref(double v_ref) { average_speed_ = v_ref; }

  [[nodiscard]] bool reached_goal(double robot_x, double robot_y, double threshold = 0.01) const {
    if (ref_traj_.size2() == 0) {
      return false;
    }
    
    int last_idx = static_cast<int>(ref_traj_.size2()) - 1;
    double goal_x = static_cast<double>(ref_traj_(0, last_idx));
    double goal_y = static_cast<double>(ref_traj_(1, last_idx));
    double dist = std::hypot(robot_x - goal_x, robot_y - goal_y);
    // Check if we're at the end of trajectory and close to final point
    return k_ >= last_idx - 1 && dist < threshold;
  }

  void set_ref_traj(std::vector<rerun::Position2D>& xy) {
    auto xy_diff = diff(xy);

    // Compute heading angles from path tangent
    auto angles = casadi::DM::atan2(
      xy_diff(casadi::Slice(), 1), xy_diff(casadi::Slice(), 0)
    );
    angles = casadi::DM::vertcat({angles(0), angles});

    // Unwrap angles to avoid discontinuities at ±π
    for (size_t i = 1; i < xy.size(); i++) {
      double prev = static_cast<double>(angles(i - 1));
      double curr = static_cast<double>(angles(i));
      double diff = curr - prev;
      while (diff > M_PI) diff -= 2 * M_PI;
      while (diff < -M_PI) diff += 2 * M_PI;
      angles(i) = prev + diff;
    }

    // Build reference trajectory: [x, y, θ]
    casadi::DM ref(3, static_cast<int>(xy.size()));
    for (size_t i = 0; i < xy.size(); i++) {
      ref(0, i) = xy[i].x();
      ref(1, i) = xy[i].y();
      ref(2, i) = angles(i);
    }
    ref_traj_ = ref;
    k_ = 0;
  }

 private:
  int N_;
  int num_states_;
  int num_inputs_;
  double dt_;
  double v_weight_;
  double average_speed_ = 1.0;
  int k_;
  casadi::DM ref_traj_;
  casadi::DM last_u_;           // For warm-starting (full horizon)
  casadi::Opti opti_;
  casadi::MX Q_;
  casadi::MX R_;
  casadi::MX x_;
  casadi::MX u_;
  casadi::MX x0_;
  casadi::MX r_;
  casadi::MX v_ref_;            // Velocity reference parameter
};
