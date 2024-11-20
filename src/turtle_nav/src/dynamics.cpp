#include "dynamics.h"

casadi::MX unicycle_dynamics(const casadi::MX& x, const casadi::MX& u) {
  auto theta = x(2);
  auto v = x(3);
  auto omega = x(4);
  auto a = u(0);
  auto alpha = u(1);

  return casadi::MX::vertcat({
    v * casadi::MX::cos(theta),
    v * casadi::MX::sin(theta),
    omega,
    a,
    alpha,
  });
}
