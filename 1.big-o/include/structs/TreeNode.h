#ifndef TREENODE_H
#define TREENODE_HH

#include <memory>

struct TreeNode {
    int value;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

#endif // TREENODE_H