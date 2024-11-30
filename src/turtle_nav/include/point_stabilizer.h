#pragma once

#include <casadi/casadi.hpp>
#include <cstdint>

class PointStabilizer {
 public:
  struct Options {
    int horizon_length;
    int state_dim;
    int input_dim;
    double dt;
    casadi::DM Q;
    casadi::DM R;
  };

  PointStabilizer() = default;
  explicit PointStabilizer(const Options& options);
  ~PointStabilizer() = default;

  void init();

  casadi::DM step(const casadi::DM& x);

  void set_target(const casadi::DM& r) { opti_.set_value(r_, r); }

 private:
  int N_;
  int num_states_;
  int num_inputs_;
  double dt_;
  casadi::Opti opti_;
  casadi::MX Q_;
  casadi::MX R_;
  casadi::MX x_;
  casadi::MX u_;
  casadi::MX x0_;
  casadi::MX r_;
};
