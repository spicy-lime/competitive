#include "TwoPointers.hpp"

std::pair<int, int> pairWithTargetSum(const std::vector<int>& arr, int targetSum)
{
    auto end = arr.size();
    size_t start = 0;
    while(start < end)
    {
        auto sum = arr[start] + arr[end];
        if(sum == targetSum)
        {
            return std::make_pair(start, end);
        }
        if(sum > targetSum)
        {
            --end;
        }
        if(sum < targetSum)
        {
            ++start;
        }
    }
    return std::make_pair(-1, -1);
}