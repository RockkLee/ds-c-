#include <iostream>
#include <vector>
// #include <algorithm>
#include <iterator>

#include "PriorityQueue.h"

void PriorityQueue::minHeapify(int idxCurParent, int idxLastNode, std::vector<std::pair<int, std::string>>& vec) {
    //The index of the current node's left child and right child 
    int lChild = idxCurParent * 2 + 1;
    int rChild = idxCurParent * 2 + 2;

    //the index of the largest element compared to the current node and its adjacent left and right child nodes
    int smallest = idxCurParent;
    if (lChild <= idxLastNode && vec[lChild].first < vec[smallest].first)
        smallest = lChild;
    if (rChild <= idxLastNode && vec[rChild].first < vec[smallest].first)
        smallest = rChild;
    
    //Keep swapping if the largest is not the current node (current parent node)
    if (smallest != idxCurParent) {
        std::swap(vec[idxCurParent], vec[smallest]);
        //Recursively heapify the affected sub-tree from either the left or right child of the current node
        minHeapify(smallest, idxLastNode, vec);
    }   
}
// void PriorityQueue::buildMinHeap(std::vector<std::pair<int, std::string>> &vec) {
//     //The index of the last node's parent
//     int idxLastNode = vec.size() - 1;
//     int idxLastNodeParent = idxLastNode / 2;
//     for (int i = idxLastNodeParent; i >=0; i--) {
//         minHeapify(i, idxLastNode, vec);
//     }
// }
void PriorityQueue::bubbleUp(int idx) {
    int parent = (idx - 1) / 2;
    //Only iterate and swap from the parent of the last element -> n/2 -> O(n)
    //This is because we only need to make sure that the new element is in the correct position
    while (idx > 0 && pq[idx].first < pq[parent].first) {
        std::swap(pq[idx], pq[parent]);
        idx = parent;
        parent = (idx - 1) / 2;
    }
}
void PriorityQueue::enqueue(int priority, const std::string &item) {
    pq.push_back({priority, item});
    
    // dumb implementation: buildMinHeap(O(n) * minHeapify(O(log(n)))) is O(nlog(n))
    // buildMinHeap(pq);

    // smart implementation: buildMinHeap is O(n)
    bubbleUp(pq.size() - 1);
}

std::pair<int, std::string> PriorityQueue::dequeue() {
    if (pq.empty())
        throw std::runtime_error("Priority queue is empty");
    
    std::pair<int, std::string> item = pq[0];
    std::swap(pq[0], pq[pq.size() - 1]);
    pq.pop_back();
    minHeapify(0, pq.size() - 1, pq);
    return item;
}

void PriorityQueue::print() {
    for (auto item : pq) {
        std::cout << item.first << ":" << item.second << ",";
    }
}

int PriorityQueue::getSize() {
    return pq.size();
}
