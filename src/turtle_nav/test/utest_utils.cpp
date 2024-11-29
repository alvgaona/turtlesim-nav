#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <casadi/casadi.hpp>
#include <casadi/core/generic_expression.hpp>
#include <rerun.hpp>

#include "utils.h"

TEST(DiffTest, BasicDiffOperations) {
  std::vector<rerun::Position2D> points = {
    rerun::Position2D(1.0, 2.0),
    rerun::Position2D(4.0, 6.0),
    rerun::Position2D(8.0, 9.0)
  };

  casadi::DM result = diff(points);

  // Expected differences:
  // Point 2 - Point 1: (4.0 - 1.0, 6.0 - 2.0) = (3.0, 4.0)
  // Point 3 - Point 2: (8.0 - 4.0, 9.0 - 6.0) = (4.0, 3.0)

  ASSERT_EQ(result.size1(), 2);  // Should have 2 rows (n-1 differences)
  ASSERT_EQ(result.size2(), 2);  // Should have 2 columns (x and y differences)

  ASSERT_NEAR(result(0, 0).scalar(), 3.0, 1e-10);  // First row, x difference
  ASSERT_NEAR(result(0, 1).scalar(), 4.0, 1e-10);  // First row, y difference
  ASSERT_NEAR(result(1, 0).scalar(), 4.0, 1e-10);  // Second row, x difference
  ASSERT_NEAR(result(1, 1).scalar(), 3.0, 1e-10);  // Second row, y difference
}
