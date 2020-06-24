#include "gtest/gtest.h"
#include "stack.hpp"

namespace collections::ut
{

namespace
{
	constexpr size_t EMPTY_STACK_SIZE = 0;
	constexpr bool IS_EMPTY = true;
	constexpr int PROPER_VALUE = 10;
	constexpr int NOT_EMPTY_STACK_SIZE = 1;
	constexpr std::optional<int> NOT_ELEMENTS_AVAIALABLE = std::nullopt;
}

using namespace collections;
using namespace ::testing;

struct StackTestSuite : Test
{
	void initSut()
	{
		sut.push(PROPER_VALUE);
	}

	stack<int> sut;
};

TEST_F(StackTestSuite, shouldAssingNotEmptyStringToOtherNotEmptyStack)
{
	initSut();
	stack<int> l_stack;
	l_stack.push(PROPER_VALUE + 1);
	l_stack.push(PROPER_VALUE + 2);

	l_stack = sut;

	ASSERT_EQ(sut.top(), l_stack.top());
}

TEST_F(StackTestSuite, shouldAssignEmptyStackToNotEmptyOne)
{
	initSut();
	stack<int> l_stack = sut;
	ASSERT_EQ(*sut.top(), *l_stack.top());
}

TEST_F(StackTestSuite, shouldAssignNotEmptyStackToEmptyOne)
{
	stack<int> l_stack;
	l_stack.push(PROPER_VALUE);
	sut = l_stack;
	ASSERT_EQ(sut.top(), l_stack.top());
}

TEST_F(StackTestSuite, shouldReturnElementOnTop)
{
	initSut();
	ASSERT_EQ(sut.top(), PROPER_VALUE);
}

TEST_F(StackTestSuite, shouldreturnNulloptWhenStackIsEmpty)
{
	ASSERT_EQ(sut.top(), NOT_ELEMENTS_AVAIALABLE);
}

TEST_F(StackTestSuite, shouldSwapNotEmptyStack)
{
	initSut();
	sut.push(PROPER_VALUE + 1);
	ASSERT_EQ(sut.top(), PROPER_VALUE + 1);
	sut.swap();
	ASSERT_EQ(sut.top(), PROPER_VALUE);
	sut.pop();
	ASSERT_EQ(sut.top(), PROPER_VALUE + 1);
}

TEST_F(StackTestSuite, shouldNotSwapEmptyStack)
{
	sut.swap();
	ASSERT_EQ(sut.empty(), IS_EMPTY);
	ASSERT_EQ(sut.size(), EMPTY_STACK_SIZE);
	ASSERT_EQ(sut.top(), NOT_ELEMENTS_AVAIALABLE);
}

TEST_F(StackTestSuite, shouldNotRemoveElementFromEmptyStack)
{
	sut.pop();
	EXPECT_EQ(sut.empty(), IS_EMPTY);
	ASSERT_EQ(sut.size(), EMPTY_STACK_SIZE);
}

TEST_F(StackTestSuite, shouldRemoveElementOnTop)
{
	initSut();
	sut.pop();
	ASSERT_EQ(sut.size(), NOT_EMPTY_STACK_SIZE - 1);
}

TEST_F(StackTestSuite, shouldReturnStackSizeFromBigStack)
{
	initSut();
	sut.push(PROPER_VALUE);

	ASSERT_EQ(sut.size(), 2);
}

TEST_F(StackTestSuite, shouldReturnStackSizeFromNotEmptyStack)
{
	initSut();
	ASSERT_EQ(sut.size(), NOT_EMPTY_STACK_SIZE);
}

TEST_F(StackTestSuite, shouldShowNotEmptyStack)
{
	initSut();
	ASSERT_EQ(sut.empty(), not IS_EMPTY);
}

TEST_F(StackTestSuite, shouldReturnZeroIfStackIsEmpty)
{
	ASSERT_EQ(sut.size(), EMPTY_STACK_SIZE);
}

TEST_F(StackTestSuite, shouldShowEmptyStack)
{
	ASSERT_EQ(sut.empty(), IS_EMPTY);
}

}
