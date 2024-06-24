#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>

#include <BigODemo.h>
# include <BST.h>

BigODemo::BigODemo() {}

void BigODemo::run() {

}

void BigODemo::bigoNSquare() {
    std::cout << std::endl << "bigoNSquare:" << std::endl;

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
    std::cout << std::endl << "bigoLogN:" << std::endl;
    // binarySearch();
    bianrySearchTree();
}

/**
 * O(log n): Binary search
 * Each step it split the search space in half until it find the target.
 * If the target it in the last half, it will take O(log n) time.
 * 
 * Array size: n
 * How many times can the array be splitted in half:
 *     Each split is n/2
 *     If the target is in the last half: n/2^k = 1
 *         n = 2^k
 *         k = log_2(n) ~ log(n)
 */
void BigODemo::binarySearch() {
    std::cout << "binarySearch:" << std::endl;
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

/**
 * O(log n): Binary search tree (BST)
 * Each step it split the search space in half until it find the target.
 * If the target it in the last half, it will take O(log n) time.
 * Number of nodes: n
 * How many times can the array be splitted in half:
 *     Each split is n/2
 *     If the target is in the last half: n/2^k = 1
 *         n = 2^k
 *         k = log_2(n) ~ log(n)
 */
void BigODemo::bianrySearchTree() {
    std::cout << "bianrySearchTree:" << std::endl;   
    
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    int searchValue = 4;
    if (tree.search(searchValue)) {
        std::cout << "Value " << searchValue << " found in the tree." << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the tree." << std::endl;
    }

    std::cout << "Tree Structure:" << std::endl;
    tree.print();

}