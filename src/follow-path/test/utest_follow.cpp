#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(StringTest, BasicStringOperations) {
  std::string test_string = "Hello World";

  ASSERT_EQ(test_string.length(), 11);
  ASSERT_EQ(test_string[0], 'H');

  ASSERT_TRUE(test_string.find("World") != std::string::npos);

  test_string += "!";
  ASSERT_EQ(test_string, "Hello World!");

  test_string = test_string.substr(0, 5);
  ASSERT_EQ(test_string, "Hello");
}
