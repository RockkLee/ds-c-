#ifndef SORTALGO_H
#define SORTALGO_H

#include <iostream>
#include <vector>

struct QuickSortStruct {
    std::vector<int> lessPart;
    std::vector<int> greaterPart;
};


class SortAlgo {
private:
    //for merge sort
    std::vector<int> merge(std::vector<int>, std::vector<int>);

    //for heap sort
    void buildMaxHeap(std::vector<int>&);
    void maxHeapify(int, int, std::vector<int>&);
public:
    SortAlgo();

    std::vector<int> bubbleSort(std::vector<int>);
    std::vector<int> insertionSort(std::vector<int>);
    std::vector<int> mergeSort(std::vector<int>);
    std::vector<int> quickSort(std::vector<int>);
    void quickSort2(std::vector<int>&, int, int);
    void heapSort(std::vector<int>&);

};


#endif //SORTALGO_H