#include "gtest/gtest.h"
#include "function_sample.hpp"

TEST(test_suite_example, should_add_two_digits) {
	EXPECT_EQ(2, add(1, 1));
}