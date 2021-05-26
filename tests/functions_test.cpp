#include "../libs/functions.hpp"
#include <gtest/gtest.h>

TEST(get_test, should_return_10)
{
    ASSERT_EQ(10, get());
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}