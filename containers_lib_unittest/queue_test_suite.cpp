#include "gtest/gtest.h"
#include "queue.hpp"


namespace collections::ut
{

namespace
{
	constexpr int EMPTY_QUEUE_SIZE = 0;
	constexpr int PROPER_VALUE = 100;
	constexpr int NOT_EMPTY_QUEUE_SIZE = 1;
	constexpr std::optional<int> NOT_VALID_VALUE = std::nullopt;
}

using namespace collections;
using namespace ::testing;

struct QueueTestSuite : Test
{
	void initQueue(queue<int>& container)
	{
		container.push(PROPER_VALUE);
	}

	void initQueueWithTwoElements(queue<int>& container)
	{
		initQueue(container);
		container.push(PROPER_VALUE + 1);
	}

	queue<int> sut;
};

TEST_F(QueueTestSuite, shouldSwapContentOfNotEmptyQueue)
{
	initQueueWithTwoElements(sut);
	sut.push(PROPER_VALUE + 2);

	sut.swap();

	ASSERT_EQ(sut.front(), PROPER_VALUE + 2);
	ASSERT_EQ(sut.back(), PROPER_VALUE);
}

TEST_F(QueueTestSuite, shouldNotSwapEmptyQueue)
{
	sut.swap();
	ASSERT_EQ(sut.front(), NOT_VALID_VALUE);
	ASSERT_EQ(sut.back(), NOT_VALID_VALUE);
}

TEST_F(QueueTestSuite, shouldRemoveFirstElementOfNotEmptyQueue)
{
	initQueueWithTwoElements(sut);
	sut.pop();
	ASSERT_EQ(sut.front(), PROPER_VALUE + 1);
}

TEST_F(QueueTestSuite, shouldNotRemoveAnythingFromEmptyQueue)
{
	sut.pop();
	ASSERT_EQ(sut.back(), NOT_VALID_VALUE);
}

TEST_F(QueueTestSuite, shouldAssignNotEmptyQueueToOtherNotEmptyQueue)
{
	initQueueWithTwoElements(sut);
	queue<int> l_queue;
	l_queue.emplace(15);
	l_queue.emplace(16);

	l_queue = sut;
	ASSERT_EQ(*sut.back(), *l_queue.back());
}

TEST_F(QueueTestSuite, shouldAssignEmptyQueueToNotEmptyOne)
{
	initQueue(sut);
	queue<int> l_queue;
	l_queue = sut;

	ASSERT_EQ(sut.back(), l_queue.back());
}

TEST_F(QueueTestSuite, shouldAssignQueueToEmptyQueue)
{
	queue<int> l_queue;
	initQueueWithTwoElements(l_queue);
	sut = l_queue;

	ASSERT_EQ(sut.back(), PROPER_VALUE + 1);
}

TEST_F(QueueTestSuite, shouldAssignEmptyQueueToOtherEmptyQueue)
{
	queue<int> l_queue;
	sut = l_queue;
	ASSERT_EQ(sut.size(), sut.size());
}

TEST_F(QueueTestSuite, shouldAddNewCreatedElementIntoNotEmptyQueue)
{
	initQueue(sut);
	sut.emplace(101);
	ASSERT_EQ(sut.back(), 101);
}

TEST_F(QueueTestSuite, shouldAddNewCreatedElementIntoEmptyQueue)
{
	sut.emplace(101);
	ASSERT_EQ(sut.back(), 101);
}

TEST_F(QueueTestSuite, shouldReturnFirstElemenetFromNotEmptyQueue)
{
	initQueueWithTwoElements(sut);
	ASSERT_EQ(sut.front(), PROPER_VALUE);
}

TEST_F(QueueTestSuite, shouldNotReturnFirstValueFromEmptyQueue)
{
	ASSERT_EQ(sut.front(), NOT_VALID_VALUE);
}

TEST_F(QueueTestSuite, shouldNotReturnLastValueFromEmptyQueue)
{
	ASSERT_EQ(sut.back(), NOT_VALID_VALUE);
}

TEST_F(QueueTestSuite, shouldReturnLastElementOfNotEmptyQueue)
{
	initQueueWithTwoElements(sut);
	ASSERT_EQ(sut.back(), PROPER_VALUE + 1);
}

TEST_F(QueueTestSuite, shouldInsertIntoNotEmptyQueue)
{
	initQueue(sut);
	sut.push(PROPER_VALUE);
	EXPECT_FALSE(sut.empty());
	EXPECT_EQ(sut.size(), NOT_EMPTY_QUEUE_SIZE + 1);

	ASSERT_EQ(sut.back(), PROPER_VALUE);
}

TEST_F(QueueTestSuite, shouldInsertNewElementIntoEmptyQueue)
{
	initQueue(sut);
	EXPECT_FALSE(sut.empty());
	EXPECT_EQ(sut.size(), NOT_EMPTY_QUEUE_SIZE);

	ASSERT_EQ(sut.back(), PROPER_VALUE);
}

TEST_F(QueueTestSuite, shouldReturnTrueWhenQueueIsEmpty)
{
	ASSERT_TRUE(sut.empty());
}

TEST_F(QueueTestSuite, shouldReturnFalseWhenQueueIsEmpty)
{
	initQueue(sut);
	ASSERT_FALSE(sut.empty());
}

TEST_F(QueueTestSuite, shouldReturnZeroSizeFromEmptyQueue)
{
	ASSERT_EQ(sut.size(), EMPTY_QUEUE_SIZE);
}

TEST_F(QueueTestSuite, shouldReturnElementsCountFromNotEmptyQueue)
{
	sut.push(PROPER_VALUE);
	ASSERT_EQ(sut.size(), NOT_EMPTY_QUEUE_SIZE);
}

}
