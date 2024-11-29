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
