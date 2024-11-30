#pragma once

#include <casadi/casadi.hpp>
#include <cstdint>
#include <rerun.hpp>

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
  };

  TrajectoryTracker() = default;
  explicit TrajectoryTracker(const Options& options);
  ~TrajectoryTracker() = default;

  void init();

  casadi::DM step(const casadi::DM& x);

  void set_target(const casadi::DM& r) { opti_.set_value(r_, r); }

  void set_ref_traj(std::vector<rerun::Position2D>&& xy) {
    auto xy_diff = diff(xy);

    auto angles = casadi::DM::atan2(
      xy_diff(casadi::Slice(), 1), xy_diff(casadi::Slice(), 0)
    );

    angles = casadi::DM::vertcat({angles(0), angles});

    casadi::DM ref(3, static_cast<int>(xy.size()));
    for (size_t i = 0; i < xy.size(); i++) {
      ref(0, i) = xy[i].x();
      ref(1, i) = xy[i].y();
      ref(2, i) = angles(i);
    }
    ref_traj_ = ref;
  }

 private:
  int N_;
  int num_states_;
  int num_inputs_;
  double dt_;
  int k_;
  casadi::DM ref_traj_;
  casadi::Opti opti_;
  casadi::MX Q_;
  casadi::MX R_;
  casadi::MX x_;
  casadi::MX u_;
  casadi::MX x0_;
  casadi::MX r_;
};
