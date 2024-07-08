#include <stdio.h>
#include <iostream>
#include <memory>

#include <Node.h>
#include <BST.h>
#include <PriorityQueue.h>

void funcBST() {
    /**
     *        12
     *       /  \
     *      6    18
     *     / \   / \
     *    3  9  15  21
     *                \
     *                24
     */
    BST tree = BST();
    tree.insert(std::make_shared<Node>(12));
    tree.insert(std::make_shared<Node>(6));
    tree.insert(std::make_shared<Node>(18));
    tree.insert(std::make_shared<Node>(3));
    tree.insert(std::make_shared<Node>(9));
    tree.insert(std::make_shared<Node>(15));
    tree.insert(std::make_shared<Node>(21));
    tree.insert(std::make_shared<Node>(24));

    std::cout << "bft: ";
    tree.bft();
    std::cout << std::endl;

    // root, left, right
    std::cout << "preOrder: ";
    tree.preOrder(tree.root);
    std::cout << std::endl;

    // left, root, right
    std::cout << "inOrder: ";
    tree.inOrder(tree.root);
    std::cout << std::endl;

    // left, right, root
    std::cout << "postOrder: ";
    tree.postOrder(tree.root);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "searchRecursively: ";
    std::cout << tree.searchRecursively(24)->data << std::endl;
    std::cout << "searchIteratively: ";
    std::cout << tree.searchIteratively(24)->data << std::endl;

    auto result = tree.searchRecursively(-10);
    if (result == nullptr) {
        std::cout << "searchRecursively: ";
        std::cout << "not found" << std::endl;
    } else {
        std::cout << "searchRecursively: ";
        std::cout << "found" << std::endl;
    }
    result = tree.searchIteratively(-10);
    if (result == nullptr) {
        std::cout << "searchIteratively: ";
        std::cout << "not found" << std::endl;
    } else {
        std::cout << "searchIteratively: ";
        std::cout << "found" << std::endl;
    }
}

void funcPriorityQueue() {
    PriorityQueue pq = PriorityQueue();
    pq.enqueue(2, "20");
    pq.enqueue(1, "10");
    pq.enqueue(7, "70");
    pq.enqueue(3, "30");
    pq.enqueue(5, "50");
    pq.dequeue();
    pq.dequeue();
    pq.enqueue(6, "60");
    pq.enqueue(4, "40");
    pq.enqueue(1, "10");
    pq.enqueue(2, "20");
    std::cout << "queue(minHeap): ";
    pq.print();
    std::cout << std::endl;

    std::cout << "queueSize: " << pq.getSize() << std::endl;
    std::cout << "queue(dequeue): ";
    while(pq.getSize() > 0) {
        std::pair<int, std::string> item = pq.dequeue();
        std::cout << item.first << ":" << item.second << ",";
    }
    std::cout << std::endl;
}

int main(int, char**){
    printf("Hello, from tree!\n");

    // funcBST();
    funcPriorityQueue();
}