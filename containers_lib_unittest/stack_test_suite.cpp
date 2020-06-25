#include "gtest/gtest.h"
#include "stack.hpp"


namespace collections::ut
{

namespace
{
	constexpr size_t EMPTY_STACK_SIZE = 0;
	constexpr int PROPER_VALUE = 10;
	constexpr int NOT_EMPTY_STACK_SIZE = 1;
	constexpr std::optional<int> NOT_ELEMENTS_AVAIALABLE = std::nullopt;
}

using namespace collections;
using namespace ::testing;

struct StackTestSuite : Test
{
	void initStack(stack<int>& container)
	{
		container.push(PROPER_VALUE);
	}

	void initStackWithTwoElements(stack<int>& container)
	{
		initStack(container);
		container.push(PROPER_VALUE + 1);
	}

	stack<int> sut;
};

TEST_F(StackTestSuite, shouldAssingNotEmptyStringToOtherNotEmptyStack)
{
	initStack(sut);
	stack<int> l_stack;
	initStackWithTwoElements(l_stack);
	l_stack = sut;

	ASSERT_EQ(sut.top(), l_stack.top());
}

TEST_F(StackTestSuite, shouldAssignEmptyStackToNotEmptyOne)
{
	initStack(sut);
	stack<int> l_stack = sut;

	ASSERT_EQ(*sut.top(), *l_stack.top());
}

TEST_F(StackTestSuite, shouldAssignNotEmptyStackToEmptyOne)
{
	stack<int> l_stack;
	initStack(l_stack);
	sut = l_stack;

	ASSERT_EQ(sut.top(), l_stack.top());
}

TEST_F(StackTestSuite, shouldReturnElementOnTop)
{
	initStack(sut);
	ASSERT_EQ(sut.top(), PROPER_VALUE);
}

TEST_F(StackTestSuite, shouldreturnNulloptWhenStackIsEmpty)
{
	ASSERT_EQ(sut.top(), NOT_ELEMENTS_AVAIALABLE);
}

TEST_F(StackTestSuite, shouldSwapNotEmptyStack)
{
	initStackWithTwoElements(sut);
	ASSERT_EQ(sut.top(), PROPER_VALUE + 1);
	sut.swap();
	ASSERT_EQ(sut.top(), PROPER_VALUE);
	sut.pop();
	ASSERT_EQ(sut.top(), PROPER_VALUE + 1);
}

TEST_F(StackTestSuite, shouldNotSwapEmptyStack)
{
	sut.swap();
	ASSERT_TRUE(sut.empty());
	ASSERT_EQ(sut.size(), EMPTY_STACK_SIZE);
	ASSERT_EQ(sut.top(), NOT_ELEMENTS_AVAIALABLE);
}

TEST_F(StackTestSuite, shouldNotRemoveElementFromEmptyStack)
{
	sut.pop();
	EXPECT_TRUE(sut.empty());
	ASSERT_EQ(sut.size(), EMPTY_STACK_SIZE);
}

TEST_F(StackTestSuite, shouldRemoveElementOnTop)
{
	initStack(sut);
	sut.pop();
	ASSERT_EQ(sut.size(), NOT_EMPTY_STACK_SIZE - 1);
}

TEST_F(StackTestSuite, shouldReturnStackSizeFromBigStack)
{
	initStack(sut);
	sut.push(PROPER_VALUE);

	ASSERT_EQ(sut.size(), NOT_EMPTY_STACK_SIZE + 1);
}

TEST_F(StackTestSuite, shouldReturnStackSizeFromNotEmptyStack)
{
	initStack(sut);
	ASSERT_EQ(sut.size(), NOT_EMPTY_STACK_SIZE);
}

TEST_F(StackTestSuite, shouldShowNotEmptyStack)
{
	initStack(sut);
	ASSERT_FALSE(sut.empty());
}

TEST_F(StackTestSuite, shouldReturnZeroIfStackIsEmpty)
{
	ASSERT_EQ(sut.size(), EMPTY_STACK_SIZE);
}

TEST_F(StackTestSuite, shouldShowEmptyStack)
{
	ASSERT_TRUE(sut.empty());
}

}
