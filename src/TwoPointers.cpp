#include <map>
#include "TwoPointers.hpp"

std::pair<int, int> pairWithTargetSum(const std::vector<int>& arr, int targetSum)
{
    auto end = arr.size() - 1;
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


std::pair<int, int> pairWithTargetSumHash(const std::vector<int>& arr, int targetSum)
{
    std::map<int, int> itemsMap;
    int first = 0;
    int second = 0;
    for(int i = 0; i < arr.size(); ++i)
    {
        auto solution = targetSum - arr[i];
        if(itemsMap.contains(solution))
        {
            return std::make_pair(itemsMap[solution], i);
        }
        else
        {
            itemsMap[arr[i]] = i;
        }
    }
    return std::make_pair(-1, -1);
}
