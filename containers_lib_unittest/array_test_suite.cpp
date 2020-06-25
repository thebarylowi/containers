#include "gtest/gtest.h"
#include "array.hpp"

#include <optional>


namespace collections::ut
{

using namespace ::testing;
using namespace collections;

namespace
{
	constexpr int PROPER_VALUE = 3;
	constexpr size_t NOT_EMPTY_ARRAY_SIZE = 5;
	constexpr std::optional<int> INVALID_ARRAY_ELEMENT = std::nullopt;
	constexpr size_t MAX_CAPACITY = sizeof(size_t);
}

struct EmptyArrayTestSuite : Test
{
	array<int, 0> sut;
};

TEST_F(EmptyArrayTestSuite, shouldThrowWhenTryToAccesEmptyArray)
{
	ASSERT_THROW(sut.at(0), std::out_of_range);
}

TEST_F(EmptyArrayTestSuite, shouldReturnMaxSize)
{
	ASSERT_EQ(sut.max_size(), MAX_CAPACITY);
}

TEST_F(EmptyArrayTestSuite, shouldBeEmpty)
{
	ASSERT_TRUE(sut.empty());
}

TEST_F(EmptyArrayTestSuite, shouldReturnNullptrWhenAccesingData)
{
	ASSERT_EQ(sut.data(), nullptr);
}

TEST_F(EmptyArrayTestSuite, shouldNotReturnAnyElementFromEmptyList)
{
	ASSERT_EQ(sut.front(), INVALID_ARRAY_ELEMENT);
}

TEST_F(EmptyArrayTestSuite, shouldNotReturnAnyBackElementFromEmptyList)
{
	ASSERT_EQ(sut.back(), INVALID_ARRAY_ELEMENT);
}

struct ArrayTestSuite : Test
{
	array<int, NOT_EMPTY_ARRAY_SIZE> sut{PROPER_VALUE, 2, PROPER_VALUE, 4, PROPER_VALUE + 1};
};

TEST_F(ArrayTestSuite, shouldSwapContentOfArray)
{
	array<int, NOT_EMPTY_ARRAY_SIZE> l_array{ PROPER_VALUE + 1, 4, PROPER_VALUE, 2, PROPER_VALUE };
	sut.swap();
	ASSERT_EQ(sut, l_array);
}

TEST_F(ArrayTestSuite, shouldFillArrayWithSpecificValue)
{
	sut.fill(PROPER_VALUE);
	array<int, 5> l_array{ PROPER_VALUE, PROPER_VALUE, PROPER_VALUE, PROPER_VALUE, PROPER_VALUE };
	for (size_t i = 0; i < l_array.size(); ++i)
	{
		ASSERT_EQ(sut.at(i), l_array.at(i));
	}
}

TEST_F(ArrayTestSuite, shouldReturnMaxSize)
{
	ASSERT_EQ(sut.max_size(), MAX_CAPACITY);
}

TEST_F(ArrayTestSuite, shouldntBeEmpty)
{
	ASSERT_FALSE(sut.empty());
}

TEST_F(ArrayTestSuite, shouldReturnLastElementOfNotEmptyList)
{
	ASSERT_EQ(sut.back(), PROPER_VALUE + 1);
}

TEST_F(ArrayTestSuite, shouldReturnFirstElementOfNotEmptyList)
{
	ASSERT_EQ(sut.front(), PROPER_VALUE);
}

TEST_F(ArrayTestSuite, shouldReturnElementValueAtSpecificPosition)
{
	ASSERT_EQ(sut.at(2), PROPER_VALUE);
}

TEST_F(ArrayTestSuite, shouldReturnElementOnSpecificPosition)
{
	ASSERT_EQ(sut[2], PROPER_VALUE);
}

}
