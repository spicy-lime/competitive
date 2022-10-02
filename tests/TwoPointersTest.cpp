#include <gtest/gtest.h>
#include <vector>
#include <utility>

#include "TwoPointers.hpp"

TEST(targetPair, test)
{
    std::vector<std::pair<std::vector<int>, int>> tests =
    {
        {{1, 2, 3, 4, 6}, 6},
        {{2, 5, 9, 11}, 11}
    };

    auto res = pairWithTargetSum(std::get<0>(tests[0]), std::get<1>(tests[0]));
    EXPECT_EQ(res, std::make_pair(1, 3));

    res = pairWithTargetSum(std::get<0>(tests[1]), std::get<1>(tests[1]));
    EXPECT_EQ(res, std::make_pair(0, 2));

}