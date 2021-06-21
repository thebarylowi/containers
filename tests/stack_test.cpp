#include <gtest/gtest.h>
#include "../libs/stack.hpp"

namespace ut
{
using namespace ::testing;
using namespace container;

namespace
{
constexpr size_t EXPECTED_SIZE_WHEN_STACK_IS_EMPTY = 0;
constexpr size_t EXPECTED_SIZE_WHEN_STACK_IS_NOT_EMPTY = 1;
constexpr int NON_ZERO_VALUE = 11;
}

struct StackTestSuite : Test
{
    stack<int> sut;
};

TEST_F(StackTestSuite, shouldPopFirstElementInNonEmptyStack)
{
    sut.push(NON_ZERO_VALUE);
    sut.push(NON_ZERO_VALUE);
    stack<int> non_empty;
    non_empty.push(NON_ZERO_VALUE);

    sut.pop();

    ASSERT_EQ(non_empty.size(), sut.size());
    ASSERT_EQ(non_empty, sut);
}

TEST_F(StackTestSuite, shouldDoNotChangeEmptyStack)
{
    stack<int> empty;

    sut.pop();
    ASSERT_EQ(sut.size(), EXPECTED_SIZE_WHEN_STACK_IS_EMPTY);
    ASSERT_EQ(sut, empty);
}

TEST_F(StackTestSuite, shouldReturnValueFromTopWhenStackIsNonEmpty)
{
    sut.push(NON_ZERO_VALUE);
    ASSERT_EQ(*sut.top(), NON_ZERO_VALUE);
}

TEST_F(StackTestSuite, shouldReturnNulloptWhenStackIsEmpty)
{
    ASSERT_EQ(sut.top(), std::nullopt);
}

TEST_F(StackTestSuite, shouldReturnFalseWhenStackIsNotEmpty)
{
    sut.push(NON_ZERO_VALUE);
    ASSERT_FALSE(sut.empty());
}

TEST_F(StackTestSuite, shouldReturnTrueWhenStackIsEmpty)
{
    ASSERT_TRUE(sut.empty());
}

TEST_F(StackTestSuite, shouldSwapContentInStack)
{
    sut.push(NON_ZERO_VALUE);
    sut.push(NON_ZERO_VALUE + 1);
    sut.push(NON_ZERO_VALUE + 2);
    stack<int> expected;
    expected.push(NON_ZERO_VALUE + 2);
    expected.push(NON_ZERO_VALUE + 1);
    expected.push(NON_ZERO_VALUE);

    sut.swap();

    ASSERT_EQ(expected, sut);
}

TEST_F(StackTestSuite, shouldEmplaceWhenStacIsEmpty)
{
    stack<int> expected;
    expected.push(101);
    sut.emplace(101);
    ASSERT_EQ(EXPECTED_SIZE_WHEN_STACK_IS_NOT_EMPTY, sut.size());
    ASSERT_EQ(expected, sut);
}

TEST_F(StackTestSuite, shouldEmplaceWhenStacIsNotEmpty)
{
    stack<int> expected;
    expected.push(102);
    expected.push(101);
    sut.push(102);

    sut.emplace(101);

    ASSERT_EQ(EXPECTED_SIZE_WHEN_STACK_IS_NOT_EMPTY + 1, sut.size());
    ASSERT_EQ(expected, sut);
}

TEST_F(StackTestSuite, shouldReturnOneWhenStackIsNotEmpty)
{
    sut.push(NON_ZERO_VALUE);
    ASSERT_EQ(EXPECTED_SIZE_WHEN_STACK_IS_NOT_EMPTY, sut.size());
}

TEST_F(StackTestSuite, shouldReturnZeroWhenStackIsEmpty)
{
    ASSERT_EQ(EXPECTED_SIZE_WHEN_STACK_IS_EMPTY, sut.size());
}

}