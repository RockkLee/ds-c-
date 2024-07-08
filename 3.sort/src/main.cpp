#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include "SortAlgo.h"

int main(int, char**){
    printf("Hello, from sort!\n");
    SortAlgo sortAlgo;
    
    std::vector<int> vec = {4, 7, 1, 2, 5, 3};
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
    
    // vec = sortAlgo.bubbleSort(vec);
    // vec = sortAlgo.insertionSort(vec);
    // vec = sortAlgo.mergeSort(vec);
    // vec = sortAlgo.quickSort(vec);
    // sortAlgo.quickSort2(vec, 0, vec.size() - 1);
    sortAlgo.heapSort(vec);

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    return 0;
}
