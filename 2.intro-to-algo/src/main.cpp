#include <stdio.h>
#include <iostream>
#include <vector>

#include "PointerAlgo.h"
#include "SlidingWindowAlgo.h"

int main(int, char**){
    printf("Hello, from intro-to-algo!\n");
    
    // pointer & counter algorithm
    /*
    PointerCounterAlgo pointerAlgo;
    std::vector<int> nums = {-11, 0, 1, 2, 3, 9, 14, 17, 21};

    std::cout << "The smart algo:" << std::endl;
    std::cout << "The average pair is: ";
    std::map<int, int> avgPair = pointerAlgo.averagPair(nums, 1.5);
    for (auto it = avgPair.begin(); it != avgPair.end(); it++)
        std::cout << "(" << it->first << " and " << it->second << "),";
    std::cout << std::endl;

    std::cout << "The dumb algo:" << std::endl;
    std::cout << "The average pair is: ";
    std::map<int, int> dumbAvgPair = pointerAlgo.dumbAveragPair(nums, 1.5);
    for (auto it = dumbAvgPair.begin(); it != dumbAvgPair.end(); it++)
        std::cout << "(" << it->first << " and " << it->second << "),";
    std::cout << std::endl;
    */
    
    // sliding window algorithm
    SlidingWindowAlgo slidingAlgo;
    std::vector<int> nums = {-11, 0, 1, 2, 3, 9, 14, 17, 21};
    std::cout << "The max sum is: " << slidingAlgo.maxSum(nums, 3) << std::endl;
    std::cout << "The dumb max sum is: " << slidingAlgo.dumbMaxSum(nums, 3) << std::endl;

    return 0;
}
