#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <queue>
#include <vector>
#include <stdexcept>
#include <string>

class PriorityQueue {
public:
    void enqueue(int priority, const std::string& item);
    std::pair<int, std::string> dequeue();
    void print();
    int getSize();

private:
    std::vector<std::pair<int, std::string>> pq;

    void bubbleUp(int);
    // void buildMinHeap(std::vector<std::pair<int, std::string>>&);
    
    void minHeapify(int, int, std::vector<std::pair<int, std::string>>&);
};

#endif // PRIORITYQUEUE_H