#ifndef BST_H
#define BST_H

#include <memory>
#include <structs/TreeNode.h>

// BST class
class BST {
public:
    BST();
    void insert(int value);
    bool search(int value);
    void inOrderTraversal();
    void print();

private:
    std::unique_ptr<TreeNode> root;

    std::unique_ptr<TreeNode> insertHelper(std::unique_ptr<TreeNode> node, int value);
    bool searchHelper(const TreeNode* node, int value) const;
    void inOrderTraversalHelper(const TreeNode* node) const;
    void printHelper(const TreeNode* node, std::string indent, bool isRight) const;
};

#endif // BST_H
