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

TEST(PadTest, BasicPadOperations) {
  // Create a simple 2x2 matrix
  casadi::DM input(2, 2);
  input(0, 0) = 1;
  input(0, 1) = 2;
  input(1, 0) = 3;
  input(1, 1) = 4;

  // Test column padding only
  casadi::DM col_padded = pad(input, 1, 0);
  ASSERT_EQ(col_padded.size1(), 2);  // Same number of rows
  ASSERT_EQ(col_padded.size2(), 3);  // Original columns + padding

  // Test row padding only
  casadi::DM row_padded = pad(input, 0, 1);
  ASSERT_EQ(row_padded.size1(), 3);  // Original rows + padding
  ASSERT_EQ(row_padded.size2(), 2);  // Same number of columns

  // Test both column and row padding
  casadi::DM both_padded = pad(input, 1, 1);
  ASSERT_EQ(both_padded.size1(), 3);  // Original rows + padding
  ASSERT_EQ(both_padded.size2(), 3);  // Original columns + padding

  // Check values in both_padded
  // Original values
  ASSERT_NEAR(both_padded(0, 0).scalar(), 1, 1e-10);
  ASSERT_NEAR(both_padded(0, 1).scalar(), 2, 1e-10);
  ASSERT_NEAR(both_padded(1, 0).scalar(), 3, 1e-10);
  ASSERT_NEAR(both_padded(1, 1).scalar(), 4, 1e-10);

  // Check padded column (last column should copy from original last column)
  ASSERT_NEAR(both_padded(0, 2).scalar(), 2, 1e-10);
  ASSERT_NEAR(both_padded(1, 2).scalar(), 4, 1e-10);

  // Check padded row (last row should copy from original last row)
  ASSERT_NEAR(both_padded(2, 0).scalar(), 3, 1e-10);
  ASSERT_NEAR(both_padded(2, 1).scalar(), 4, 1e-10);
  ASSERT_NEAR(both_padded(2, 2).scalar(), 4, 1e-10);
}
