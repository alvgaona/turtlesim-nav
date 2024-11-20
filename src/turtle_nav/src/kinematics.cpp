#include "kinematics.h"

casadi::MX unicycle_kinematics(const casadi::MX& x, const casadi::MX& u) {
  auto theta = x(2);
  auto v = u(0);
  auto omega = u(1);

  return casadi::MX::vertcat({
    v * casadi::MX::cos(theta),
    v * casadi::MX::sin(theta),
    omega,
  });
}

casadi::MX diffdrive_kinematics(const casadi::MX& x, const casadi::MX& u) {
  auto r = 1.0;
  auto d = 1.0;
  auto theta = x(2);
  auto u_l = u(0) - u(1);
  auto u_r = u(0) + u(1);

  return casadi::MX::vertcat({
    r / 2 * casadi::MX::cos(theta) * (u_r + u_l),
    r / 2 * casadi::MX::sin(theta) * (u_r + u_l),
    r / d * (u_r - u_l),
  });
}
