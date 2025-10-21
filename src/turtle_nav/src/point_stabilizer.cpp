#include "point_stabilizer.h"

#include <casadi/casadi.hpp>
#include <casadi/core/optistack.hpp>
#include <cstdint>

#include "kinematics.h"

PointStabilizer::PointStabilizer(const Options& options)
  : N_(options.horizon_length),
    num_states_(options.state_dim),
    num_inputs_(options.input_dim),
    dt_(options.dt) {
  Q_ = casadi::MX(options.Q);
  R_ = casadi::MX(options.R);

  x_ = opti_.variable(num_states_, N_ + 1);
  u_ = opti_.variable(num_inputs_, N_);
  x0_ = opti_.parameter(num_states_);
  r_ = opti_.parameter(num_states_);

  init();
}

void PointStabilizer::init() {
  casadi::MX J = 0;  // objective function

  for (int k = 0; k < N_; k++) {
    auto state_error = x_(casadi::Slice(0, 2), k) - r_(casadi::Slice(0, 2));

    J +=
      casadi::MX::mtimes(casadi::MX::mtimes(state_error.T(), Q_), state_error);
    J += casadi::MX::mtimes(
      casadi::MX::mtimes(u_(casadi::Slice(), k).T(), R_), u_(casadi::Slice(), k)
    );

    auto x_k = x_(casadi::Slice(), k);
    auto u_k = u_(casadi::Slice(), k);

    auto x_next = x_k + unicycle_kinematics(x_k, u_k) * dt_;

    opti_.subject_to(x_(casadi::Slice(), k + 1) == x_next);
  }

  auto final_state_error =
    x_(casadi::Slice(0, 2), N_) - r_(casadi::Slice(0, 2));
  J += casadi::MX::mtimes(
    casadi::MX::mtimes(final_state_error.T(), Q_), final_state_error
  );

  opti_.minimize(J);

  opti_.subject_to(x_(casadi::Slice(), 0) == x0_);
  opti_.subject_to(u_(0, casadi::Slice()) >= 0);
  opti_.subject_to(u_(0, casadi::Slice()) <= 1);
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

casadi::DM PointStabilizer::step(const casadi::DM& x) {
  opti_.set_value(x0_, x);
  const auto sol = opti_.solve();
  return sol.value(u_);
}
