#ifndef POINTERALGO_H
#define POINTERALGO_H

#include <vector>
#include <map>

class PointerCounterAlgo {
private:

public:
    PointerCounterAlgo();

    std::map<int, int> averagPair(std::vector<int>& nums, double target);
    std::map<int, int> dumbAveragPair(std::vector<int>& nums, double target);
};

#endif // POINTERALGO_H