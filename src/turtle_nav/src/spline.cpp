#include <spline.h>

std::vector<rerun::Position2D> planar_trajectory(
  const std::vector<rerun::Position2D>& waypoints,
  int num_points,
  int dimension,
  int degree,
  int num_samples
) {
  std::vector<tinyspline::real> ctrlp;
  for (const auto& point : waypoints) {
    ctrlp.push_back(point.x());
    ctrlp.push_back(point.y());
  }

  tinyspline::BSpline spline(num_points, dimension, degree);

  spline.setControlPoints(ctrlp);

  std::vector<rerun::Position2D> xy;

  for (auto i = 0; i < num_samples; i++) {
    double t = static_cast<double>(i) / (num_samples - 1);

    auto result = spline.eval(t).result();

    xy.emplace_back(result[0], result[1]);
  }

  return xy;
};
