#pragma once

#include <tinysplinecxx.h>

#include <rerun.hpp>
#include <vector>

std::vector<rerun::Position2D> planar_trajectory(
  const std::vector<rerun::Position2D>& waypoints,
  int num_points,
  int dimension = 2,
  int degree = 2,
  int num_samples = 1000
);
