#include "PointerAlgo.h"

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <map>

PointerCounterAlgo::PointerCounterAlgo(/* args */) {
}

/**
 * O(n): Use two pointers to find the average
 */
std::map<int, int> PointerCounterAlgo::averagPair(std::vector<int> &nums, double target) {
    std::map<int, int> avgPair;

    int lpointer = 0;
    int rpointer = nums.size() - 1;
    while (lpointer < rpointer) {
        int sum = nums[lpointer] + nums[rpointer];
        if (sum == target*2) {
            avgPair[nums[lpointer]] = nums[rpointer];
            lpointer++;
            rpointer--;
        } else if (sum < target) {
            lpointer++;
        } else {
            rpointer--;
        }
    }

    return avgPair;
}

/**
 * O(n^2): Use two loops to find the average
 */
std::map<int, int> PointerCounterAlgo::dumbAveragPair(std::vector<int> &nums, double target) {
    std::map<int, int> avgPair;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if ((nums[i] + nums[j]) == target*2) {
                avgPair[nums[i]] = nums[j];
            }
        }
    }
    return avgPair;
}
