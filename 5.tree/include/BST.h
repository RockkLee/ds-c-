#ifndef BST_H
#define BST_H

#include <memory>
#include <queue>

#include <Node.h>

class BST {
private:
    std::queue<std::shared_ptr<Node>> bftQueue;
    std::shared_ptr<Node> searchHelper(std::shared_ptr<Node> cur, int target);
    std::shared_ptr<Node> deleteNodeHelper(std::shared_ptr<Node> cur, int target);
public:
    std::shared_ptr<Node> root;

    BST();
    void insert(std::shared_ptr<Node> target);
    void bft();
    void preOrder(std::shared_ptr<Node> cur);
    void inOrder(std::shared_ptr<Node> cur);
    void postOrder(std::shared_ptr<Node> cur);
    std::shared_ptr<Node> searchRecursively(int target);
    std::shared_ptr<Node> searchIteratively(int target);
    void deleteNode(int target);
};

#endif //BST_H