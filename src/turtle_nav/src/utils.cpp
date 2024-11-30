#include "utils.h"

/**
 * Calculates the difference between consecutive 2D points.
 *
 * @param points Vector of Position2D objects representing 2D points
 * @return A casadi::DM matrix where each row contains the (x,y) differences
 *         between consecutive points. Returns empty matrix if input is empty.
 *         Matrix has dimensions (n-1) x 2 where n is number of input points.
 */
casadi::DM diff(const std::vector<rerun::Position2D>& points) {
  if (points.empty()) {
    return casadi::DM{};
  }

  auto n = static_cast<casadi_int>(points.size());

  casadi::DM result(n - 1, 2);

  for (size_t i = 0; i < points.size() - 1; i++) {
    result(i, 0) = points[i + 1].x() - points[i].x();
    result(i, 1) = points[i + 1].y() - points[i].y();
  }

  return result;
}

casadi::DM pad(const casadi::DM& input, int col_padding, int row_padding) {
  if (col_padding <= 0 && row_padding <= 0) {
    return input;
  }

  // Get dimensions of input array
  auto rows = input.size1();
  auto cols = input.size2();

  // Create the padded matrix for column padding
  casadi::DM padded = input;

  // Add column padding if needed
  if (col_padding > 0) {
    casadi::DM last_col = input(casadi::Slice(), cols - 1);
    for (int i = 0; i < col_padding; i++) {
      padded = casadi::DM::horzcat({padded, last_col});
    }
  }

  // Add row padding if needed
  if (row_padding > 0) {
    casadi::DM last_row = padded(rows - 1, casadi::Slice());
    for (int i = 0; i < row_padding; i++) {
      padded = casadi::DM::vertcat({padded, last_row});
    }
  }

  return padded;
}
