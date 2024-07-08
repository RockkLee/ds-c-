#ifndef NODE_H
#define NODE_H

#include <memory>


class Node {
public:
    int data;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    
    Node();
    Node(int data);
};

#endif //NODE_H