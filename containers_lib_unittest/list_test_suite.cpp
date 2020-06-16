#include "gtest/gtest.h"
#include "list.hpp"

namespace collections::ut
{

using namespace collections;
using namespace ::testing;

struct ListTestSuite : Test
{
	list sut;
};

TEST_F(ListTestSuite, shouldClearWholeContentListContain)
{
	sut.push_back(10);
	sut.push_back(11);
	sut.clear();
	ASSERT_EQ(sut.size(), 0);
}

TEST_F(ListTestSuite, shouldReturnZeroWhenListIsEmpty)
{
	ASSERT_EQ(sut.size(), 0);
	ASSERT_EQ(sut.empty(), true);
}

TEST_F(ListTestSuite, shouldAddNewNodeAtEndOfList)
{
	sut.push_back(10);
	EXPECT_EQ(sut.size(), 1);
	ASSERT_EQ(sut.empty(), false);
	ASSERT_EQ(sut.back(), 10);
}

}