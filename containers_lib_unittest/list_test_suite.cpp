#include "gtest/gtest.h"
#include "list.hpp"


namespace collections::ut
{

namespace
{
	constexpr std::optional<int> EMPTY_LIST = std::nullopt;
	constexpr int PROPER_VALUE = 10;
	constexpr size_t NODE_COUNT = 5;
}

using namespace collections;
using namespace ::testing;

struct ListTestSuite : Test
{
	list<int> sut;
};

TEST_F(ListTestSuite, shouldcreateNewEmptyListFromExistingEmptyList)
{
	list l_list(sut);
	EXPECT_TRUE(l_list.empty());
	ASSERT_EQ(l_list, sut);
}

TEST_F(ListTestSuite, shouldCreateNewNonEmptyListFromExistingOne)
{
	sut.push_back(PROPER_VALUE);
	list l_list(sut);
	ASSERT_EQ(sut, l_list);
}

TEST_F(ListTestSuite, shouldCreateNewNonEmptyListFromExistingListWithMoreThenOneNode)
{
	sut.push_back(PROPER_VALUE);
	sut.push_back(2);
	list l_list(sut);

	EXPECT_FALSE(l_list.empty());
	EXPECT_EQ(l_list.size(), 2);
	ASSERT_EQ(l_list, sut);
}

TEST_F(ListTestSuite, shouldCompareTwoEmptyLists)
{
	list<int> l_list;
	ASSERT_EQ(sut, l_list);
}

TEST_F(ListTestSuite, shouldCompareTwoNonEmptyLists)
{
	sut.push_back(PROPER_VALUE);
	list<int> l_list;
	l_list.push_back(PROPER_VALUE);

	ASSERT_EQ(sut, l_list);
}

TEST_F(ListTestSuite, shouldAssignFiveNodesToEmptyList)
{
	sut.assign(NODE_COUNT, PROPER_VALUE);
	ASSERT_EQ(sut.size(), NODE_COUNT);
}

TEST_F(ListTestSuite, shouldReturnFirstNodeOfNotEmptyList)
{
	sut.push_back(PROPER_VALUE);
	ASSERT_EQ(sut.front(), PROPER_VALUE);
}

TEST_F(ListTestSuite, shouldReturnDirstNodeAsNulloptFromEmptyList)
{
	ASSERT_EQ(sut.front(), EMPTY_LIST);
}

TEST_F(ListTestSuite, shouldReturnNulloptFromEmptyList)
{
	ASSERT_EQ(sut.back(), EMPTY_LIST);
}

TEST_F(ListTestSuite, shouldReturnLastNodeOfNonEmptyList)
{
	sut.push_back(1);
	sut.push_back(PROPER_VALUE);
	ASSERT_EQ(sut.back(), PROPER_VALUE);
}

TEST_F(ListTestSuite, shouldClearWholeContentListContain)
{
	sut.push_back(PROPER_VALUE);
	sut.push_back(11);
	sut.clear();
	ASSERT_EQ(sut.size(), 0);
}

TEST_F(ListTestSuite, shouldReturnZeroWhenListIsEmpty)
{
	ASSERT_EQ(sut.size(), 0);
	ASSERT_TRUE(sut.empty());
}

TEST_F(ListTestSuite, shouldAddNewNodeAtEndOfList)
{
	sut.push_back(PROPER_VALUE);
	EXPECT_EQ(sut.size(), 1);

	ASSERT_FALSE(sut.empty());
	ASSERT_EQ(sut.back(), PROPER_VALUE);
}

}
