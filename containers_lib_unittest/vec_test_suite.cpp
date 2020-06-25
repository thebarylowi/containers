#include "gtest/gtest.h"
#include "vec.hpp"

#include <numeric>
#include <exception>


namespace collections::ut
{

namespace
{
	constexpr auto VALID_VALUE = 100;
	constexpr auto INITIAL_CAPACITY_VALUE = 1;
	constexpr auto INITIAL_VEC_SIZE = 0;

	constexpr auto FIRST_VALUE = 1;
	constexpr auto LAST_VALUE = 5;
}

using namespace collections;
using namespace ::testing;

struct VectorTestSuite : Test
{
	void initVector() {
		sut.push_back(FIRST_VALUE);
		sut.push_back(2);
		sut.push_back(LAST_VALUE);
	}

	vec<int> sut;
};

TEST_F(VectorTestSuite, shouldThrowExceptionWhenTryToAccessElementOutOfVector)\
{
	ASSERT_THROW(sut.at(0), std::out_of_range);
}

TEST_F(VectorTestSuite, shouldShrinkToFitVectorContent)
{
	initVector();
	sut.emplace_back(10);
	EXPECT_EQ(sut.capacity(), 9);
	sut.shrink_to_fit();
	ASSERT_EQ(sut.capacity(), 4);
}

TEST_F(VectorTestSuite, shouldReverseVectorContent)
{
	initVector();
	sut.reverse();

	ASSERT_EQ(sut[0], LAST_VALUE);
	ASSERT_EQ(sut[2], FIRST_VALUE);
}

TEST_F(VectorTestSuite, shouldEmplaceBackNewElement)
{
	sut.emplace_back(10);
	ASSERT_EQ(sut[0], 10);
}

TEST_F(VectorTestSuite, shouldRemoveLastElementWhilePopBack)
{
	initVector();
	ASSERT_EQ(sut.size(), 3);
	sut.pop_back();
	ASSERT_EQ(sut.size(), 2);
}

TEST_F(VectorTestSuite, shouldReturnFirstValue)
{
	initVector();
	ASSERT_EQ(sut.front(), FIRST_VALUE);
}

TEST_F(VectorTestSuite, shouldReturnLastValue)
{
	initVector();
	ASSERT_EQ(sut.back(), LAST_VALUE);
}

TEST_F(VectorTestSuite, shouldRerutnIteratorWithFirstValueInVector)
{
	initVector();
	ASSERT_EQ(*sut.begin(), FIRST_VALUE);
}

TEST_F(VectorTestSuite, shouldRerutnIteratorWithLastValueInVector)
{
	initVector();
	ASSERT_EQ(*sut.end(), LAST_VALUE);
}

TEST_F(VectorTestSuite, shouldAddNewVectorElementAtTheEndOfCollecitonWithoutResizing)
{
	sut.push_back(VALID_VALUE);
	ASSERT_EQ(sut[0], VALID_VALUE);
}

TEST_F(VectorTestSuite, shouldAddNewVectorElementAtTheEndOfCollectionWithResizing)
{
	for (size_t i = 0; i < INITIAL_CAPACITY_VALUE + 1; ++i)
	{
		sut.push_back(VALID_VALUE);
	}

	ASSERT_EQ(sut[0], VALID_VALUE);
	ASSERT_EQ(sut[1], VALID_VALUE);
}

TEST_F(VectorTestSuite, shouldReturnCapacityOfVector)
{
	ASSERT_EQ(sut.capacity(), INITIAL_CAPACITY_VALUE);
}

TEST_F(VectorTestSuite, shouldReturnElementCountAlreadyInVector)
{
	ASSERT_EQ(sut.size(), INITIAL_VEC_SIZE);
}

TEST_F(VectorTestSuite, shouldShowEmptyVector)
{
	ASSERT_TRUE(sut.empty());
}

TEST_F(VectorTestSuite, shouldShowFalseToNotEmptyVector)
{
	sut.push_back(VALID_VALUE);
	ASSERT_FALSE(sut.empty());
}

struct VectorAtMethosTestSuite : VectorTestSuite, WithParamInterface<int>
{
	VectorAtMethosTestSuite()
	{
		for (size_t i = 0; i < 10; ++i)
		{
			sut.push_back(i + 1);
		}
	}
};

TEST_P(VectorAtMethosTestSuite, shouldReturnSpecificValueAtPosition)
{
	ASSERT_EQ(sut[GetParam() - 1], GetParam());
}

INSTANTIATE_TEST_SUITE_P(
	ValuesForAtMethod,
	VectorAtMethosTestSuite,
	Range(1, 10));

}
