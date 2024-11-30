#include <casadi/casadi.hpp>
#include <rerun.hpp>

casadi::DM diff(const std::vector<rerun::Position2D>& points);

casadi::DM pad(
  const casadi::DM& input, int col_padding = 0, int row_padding = 0
);
