#pragma once

#include <casadi/casadi.hpp>

casadi::MX unicycle_kinematics(const casadi::MX& x, const casadi::MX& u);

casadi::MX diffdrive_kinematics(const casadi::MX& x, const casadi::MX& u);
