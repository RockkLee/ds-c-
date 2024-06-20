#include <iostream>
#include <list>
#include <vector>
#include <BigODemo.h>
#include <iterator>
#include <algorithm>

BigODemo::BigODemo() {}

void BigODemo::run() {

}

void BigODemo::bigoNSquare() {
    
    //Traverse a square grid
    std::vector<std::vector<int>> vector2D;
    vector2D = {{1,2,3},{4,5,6},{7,8,9}};
    std::cout << "2D vector: {";
    for (auto i = vector2D.begin(); i != vector2D.end(); i++){
        std::cout << "{";
        std::copy(i->begin(), i->end(), std::ostream_iterator<int>(std::cout, ","));
        std::cout << "}";
    }
    std::cout << "}" << std::endl;
}

void BigODemo::bigoLogN() {
    // create a demo for binary search
    std::vector<int> vector;
    vector = {1,5,8,9,13,32,55,62,77,83,99};
    std::cout << "Vector: {";
    std::copy(vector.begin(), vector.end(), std::ostream_iterator<int>(std::cout, ","));
    std::cout << "}" << std::endl;

    int input = 77;
    
    int head = 0;
    int tail = vector.size() - 1;
    while (true) {
        int mid = (tail + head) / 2;

        if (vector[mid] == input) {
            std::cout << "Found: " << input << std::endl;
            break;
        }
        if (input > vector[tail] || input < vector[head]) {
            std::cout << "Not Found: " << input << std::endl;
            break;
        }

        if (input > vector[mid]) {
            head = mid + 1;
        } else {
            tail = mid - 1;
        }
    }
}