#include <gtest/gtest.h>
#include "../libs/vector.hpp"

namespace ut
{
using namespace ::testing;
using namespace container;

struct VectorTestSuit : Test
{
    vector<int> sut;
};

}