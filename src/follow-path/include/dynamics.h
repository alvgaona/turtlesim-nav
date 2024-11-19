#pragma once

#include <casadi/casadi.hpp>

casadi::MX unicycle_dynamics(const casadi::MX& x, const casadi::MX& u);
