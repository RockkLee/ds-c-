#include "SlidingWindowAlgo.h"
#include <iostream>
#include <iterator>
#include <algorithm>

SlidingWindowAlgo::SlidingWindowAlgo(/* args */) {
}

/**
 * O(n): Use the sliding window
 */
int SlidingWindowAlgo::maxSum(std::vector<int> &nums, int winSize) {
    std::cout << "[ ";
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "]";
    std::cout << std::endl;

    int maxSum = 0;
    for (int i = 0; i < winSize; i++)
        maxSum += nums[i];
    for (int i = winSize; i < nums.size(); i++) {
        maxSum = std::max(maxSum, maxSum - nums[i-winSize] + nums[i]);
    }
    return maxSum;
}

/**
 * O(n^2): Use two loops
 */
int SlidingWindowAlgo::dumbMaxSum(std::vector<int> &nums, int winSize) {
    std::cout << "[ ";
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "]";
    std::cout << std::endl;

    int maxSum = 0;
    for (int i = 0; i < nums.size() - (winSize-1); i++) {
        int sum = 0;
        for (int j = 0; j < winSize; j++)
            sum += nums[i+j];
        maxSum = std::max(maxSum, sum);
    }

    return maxSum;
}