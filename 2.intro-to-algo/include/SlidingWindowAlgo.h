#ifndef SLIDINGWINDOWALGO_H
#define SLIDINGWINDOWALGO_H

#include <vector>

class SlidingWindowAlgo
{
private:
    /* data */
public:
    SlidingWindowAlgo(/* args */);

    int maxSum(std::vector<int>& nums, int winSize);
    int dumbMaxSum(std::vector<int>& nums, int winSize);
};

#endif // SLIDINGWINDOWALGO_H