#include <gtest/gtest.h>
#include "vec.hpp"

namespace ut::containers {

namespace {
	constexpr int VALID_VALUE = 55;
}

using namespace ::testing;
using namespace ::containers;

struct VectorTestSuite : Test {
	vec sut{};
};

TEST_F(VectorTestSuite, shouldReturnIsEmptyWhenItIsJustCreatedVector) {
	EXPECT_EQ(sut.empty(), true);
}

TEST_F(VectorTestSuite, shouldReturnIsNotEmptyWhenSomethingIsPushedToVector) {
	sut.push_back(1);
	EXPECT_EQ(sut.empty(), false);
}

TEST_F(VectorTestSuite, shouldReturnValueAtSpecificPosition) {
	sut.push_back(VALID_VALUE);
	EXPECT_EQ(sut.at(0), VALID_VALUE);
}

TEST_F(VectorTestSuite, shouldSrintVectorToFit) {
	sut.shrink_to_fit();
	EXPECT_EQ(sut.size(), sut.length());
}

TEST_F(VectorTestSuite, shouldReverseContentOfVector) {
	sut.push_back(1);
	sut.push_back(2);
	sut.push_back(3);

	sut.reverse();

	EXPECT_EQ(sut.at(0), 3);
	EXPECT_EQ(sut.at(2), 1);
}

struct VectorPushBackTestSuite : VectorTestSuite, WithParamInterface<int> {};

TEST_P(VectorPushBackTestSuite, shouldAddNewValueToArray) {
	sut.push_back(GetParam());
	EXPECT_EQ(sut[0], GetParam());
}

INSTANTIATE_TEST_SUITE_P(
	ValuePushBackTest,
	VectorPushBackTestSuite,
	Values(1, 2, 3, 4, 5, 100));

struct SizeValues {
	size_t size;
	size_t push_backs_count;
};

struct VectorSizeTestSuite : VectorTestSuite, WithParamInterface<SizeValues> {};

TEST_P(VectorSizeTestSuite, shouldReturnVectorSize) {
	for (size_t i = 0; i < GetParam().push_backs_count; ++i) {
		sut.push_back(i);
	}
	EXPECT_EQ(sut.size(), GetParam().size);
}

INSTANTIATE_TEST_SUITE_P(
	SizeOfVectorTest,
	VectorSizeTestSuite,
	Values(SizeValues{ 2, 2 },
		   SizeValues{ 6, 3 }));

struct LengthValues {
	size_t length;
	size_t push_backs_count;
};

struct VectorLengthTestSuite : VectorTestSuite, WithParamInterface<LengthValues> {};

TEST_P(VectorLengthTestSuite, shouldReturnCurrentVectorLength) {
	for (size_t i = 0; i < GetParam().push_backs_count; ++i) {
		sut.push_back(i);
	}
	EXPECT_EQ(sut.length(), GetParam().length);
}

INSTANTIATE_TEST_SUITE_P(
	LengthOfVectorTest,
	VectorLengthTestSuite,
	Values(LengthValues{ 2, 2 },
		   LengthValues{ 6, 6 }));

}