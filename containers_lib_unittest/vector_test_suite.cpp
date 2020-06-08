#include <gtest/gtest.h>
#include "vec.hpp"

namespace ut::containers {

namespace {
	constexpr int VALID_VALUE = 55;
	constexpr int FIRST_VALUE = 1;
	constexpr int LAST_VALUE = 3;

	constexpr bool IS_EMPTY = true;
}

using namespace ::testing;
using namespace ::containers;

struct VectorTestSuite : Test {
	void initVector() {
		sut.push_back(FIRST_VALUE);
		sut.push_back(2);
		sut.push_back(LAST_VALUE);
	}

	vec sut{};
};

TEST_F(VectorTestSuite, shouldReturnIsEmptyWhenItIsJustCreatedVector) {
	ASSERT_EQ(sut.empty(), IS_EMPTY);
}

TEST_F(VectorTestSuite, shouldReturnIsNotEmptyWhenSomethingIsPushedToVector) {
	initVector();
	ASSERT_EQ(sut.empty(), not IS_EMPTY);
}

TEST_F(VectorTestSuite, shouldReturnValueAtSpecificPosition) {
	sut.push_back(VALID_VALUE);
	ASSERT_EQ(sut.at(0), VALID_VALUE);
}

TEST_F(VectorTestSuite, shouldSrintVectorToFit) {
	sut.shrink_to_fit();
	ASSERT_EQ(sut.size(), sut.length());
}

TEST_F(VectorTestSuite, shouldReverseContentOfVector) {
	initVector();

	sut.reverse();

	ASSERT_EQ(sut.at(0), LAST_VALUE);
	ASSERT_EQ(sut.at(2), FIRST_VALUE);
}

TEST_F(VectorTestSuite, shouldReturnBeginOfArray) {
	initVector();
	ASSERT_EQ(*sut.begin(), FIRST_VALUE);
}

TEST_F(VectorTestSuite, shouldReturnLastElemOfArray) {
	initVector();
	ASSERT_EQ(*sut.end(), LAST_VALUE);
}

TEST_F(VectorTestSuite, shouldAccessFirstElemOfVector) {
	initVector();
	ASSERT_EQ(sut.front(), FIRST_VALUE);
}

TEST_F(VectorTestSuite, shouldAccessLastElemOfVector) {
	initVector();
	ASSERT_EQ(sut.back(), LAST_VALUE);
}

TEST_F(VectorTestSuite, shouldEmplceArgumentInVector) {
	initVector();
	sut.emplace(1, 100);
	ASSERT_EQ(sut[1], 100);
}

TEST_F(VectorTestSuite, shouldNotEmplaceAnyArgumentIfPositionIsOutsideOfVectorRange) {
	initVector();
	sut.emplace(10, 100);
	ASSERT_EQ(sut[0], 1);
	ASSERT_EQ(sut[1], 2);
	ASSERT_EQ(sut[2], 3);
}

TEST_F(VectorTestSuite, shouldAsssignGivenValueToVector) {
	initVector();
	sut.assign(2, 5);
	ASSERT_EQ(sut[0], 5);
	ASSERT_EQ(sut[1], 5);
}

TEST_F(VectorTestSuite, shouldCreateelemInPlaceAtTheEndOfArray) {
	sut.emplace_back(10);
	ASSERT_EQ(sut[0], 10);
}

TEST_F(VectorTestSuite, shouldSwapContentOfTwoArrays) {
	initVector();
	vec newArray;
	newArray.push_back(10); newArray.push_back(20), newArray.push_back(30);
	sut.swap(newArray);
	ASSERT_EQ(sut[0], 10);
	ASSERT_EQ(sut[1], 20);
	ASSERT_EQ(sut[2], 30);
}

TEST_F(VectorTestSuite, shouldRemoveLastElementOfArrayWhenPopBackCalled) {
	initVector();
	sut.pop_back();
	ASSERT_EQ(sut[0], 1);
	ASSERT_EQ(sut[1], 2);
}

TEST_F(VectorTestSuite, shouldResizeArrayAndAddSomeZerosToArray) {
	initVector();
	sut.resize(4);
	ASSERT_EQ(sut[3], 0);
}

struct VectorPushBackTestSuite : VectorTestSuite, WithParamInterface<int> {};

TEST_P(VectorPushBackTestSuite, shouldAddNewValueToArray) {
	sut.push_back(GetParam());
	ASSERT_EQ(sut[0], GetParam());
}

INSTANTIATE_TEST_SUITE_P(
	ValuePushBackTest,
	VectorPushBackTestSuite,
	Range(0, 15));

struct SizeValues {
	size_t size;
	size_t push_backs_count;
};

struct VectorSizeTestSuite : VectorTestSuite, WithParamInterface<SizeValues> {};

TEST_P(VectorSizeTestSuite, shouldReturnVectorSize) {
	for (size_t i = 0; i < GetParam().push_backs_count; ++i) {
		sut.push_back(i);
	}
	ASSERT_EQ(sut.size(), GetParam().size);
}

INSTANTIATE_TEST_SUITE_P(
	SizeOfVectorTest,
	VectorSizeTestSuite,
	Values(SizeValues{ 50, 2 },
		   SizeValues{ 150, 51 }));

struct LengthValues {
	size_t length;
	size_t push_backs_count;
};

struct VectorLengthTestSuite : VectorTestSuite, WithParamInterface<LengthValues> {};

TEST_P(VectorLengthTestSuite, shouldReturnCurrentVectorLength) {
	for (size_t i = 0; i < GetParam().push_backs_count; ++i) {
		sut.push_back(i);
	}
	ASSERT_EQ(sut.length(), GetParam().length);
}

INSTANTIATE_TEST_SUITE_P(
	LengthOfVectorTest,
	VectorLengthTestSuite,
	Values(LengthValues{ 2, 2 },
		   LengthValues{ 6, 6 }));

}