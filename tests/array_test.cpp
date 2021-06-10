#include <gtest/gtest.h>
#include <cstddef>
#include <utility>
#include <optional>
#include "../libs/array.hpp"

namespace ut
{
using namespace container;
using namespace ::testing;

namespace
{
constexpr std::size_t SIZE = 100;
constexpr std::size_t INDEX_IN_BASIC_RANGE = SIZE / 2;
constexpr int EXPECTED_VALUE_FROM_EMPTY = 0;
constexpr std::size_t EMPTY_ARRAY = 0;

void fill_array(array<int, SIZE>& arr)
{
    // TODO: maybe add iota usge to fill it up?
    for (std::size_t i = 0; i < SIZE; ++i)
    {
        arr[i] = i + 1;
    }
}

bool compare_two_arrays(const array<int, SIZE>& first, const array<int, SIZE>& second)
{
    for (std::size_t i = 0; i < SIZE; ++i)
    {
        if (first.at(i) != second.at(i))
        {
            return false;
        }
    }
    return true;
}

}

struct ArrayTestSuit : Test
{
    void expectArraysAreEqual(const array<int, SIZE>& other)
    {
        ASSERT_EQ(sut.size(), other.size());
        ASSERT_TRUE(compare_two_arrays(sut, other));
    }

    array<int, SIZE> sut;
};

TEST_F(ArrayTestSuit, shouldReturnLastElementWhenArrayIsFilled)
{
    fill_array(sut);
    ASSERT_EQ(SIZE + 1, *sut.back());
}

TEST_F(ArrayTestSuit, shouldReturnNullFromEndWhenArrayIsEmpty)
{
    array<int, EMPTY_ARRAY> empty;
    ASSERT_EQ(std::nullopt, empty.back());
}


TEST_F(ArrayTestSuit, shouldReturnFirstElementWhenArrayIsFilled)
{
    fill_array(sut);
    ASSERT_EQ(1, *sut.front());
}

TEST_F(ArrayTestSuit, shouldReturnNullFromFrontWhenArrayIsEmpty)
{
    array<int, EMPTY_ARRAY> empty;
    ASSERT_EQ(std::nullopt, empty.front());
}

TEST_F(ArrayTestSuit, shouldShowThatArrayIsNotEmpty)
{
    fill_array(sut);
    ASSERT_FALSE(sut.empty());
}

TEST_F(ArrayTestSuit, shouldShowThatArrayIsEmpty)
{
    array<int, EMPTY_ARRAY> empty;
    ASSERT_TRUE(empty.empty());
}

TEST_F(ArrayTestSuit, shouldMoveDataFromOneArrayToNewOne)
{
    fill_array(sut);
    array<int, SIZE> newArray(std::move(sut));
    ASSERT_NE(sut.size(), newArray.size());
}

TEST_F(ArrayTestSuit, shouldAccessElementFromIndex)
{
    ASSERT_EQ(EXPECTED_VALUE_FROM_EMPTY, sut[INDEX_IN_BASIC_RANGE]);
}

TEST_F(ArrayTestSuit, shouldAccessElementAtGivenIndex)
{
    ASSERT_EQ(EXPECTED_VALUE_FROM_EMPTY, sut.at(INDEX_IN_BASIC_RANGE));
}

TEST_F(ArrayTestSuit, shouldCreateSameArrayFromExisitingOne)
{
    fill_array(sut);

    array<int, SIZE> newArray(sut);

    expectArraysAreEqual(newArray);
}

TEST_F(ArrayTestSuit, shouldAssignNewArray)
{
    array<int, SIZE> newArray;
    fill_array(newArray);

    sut = newArray;

    expectArraysAreEqual(newArray);
}

TEST_F(ArrayTestSuit, shouldReturnAssignedSize)
{
    ASSERT_EQ(SIZE, sut.size());
}

}