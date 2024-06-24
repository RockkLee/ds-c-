#include "BST.h"
#include <iostream>
#include <memory>

// BST constructor
BST::BST() : root(nullptr) {}

// Insert a value into the BST
void BST::insert(int value) {
    root = insertHelper(std::move(root), value);
}

// Helper function to insert a value into the BST
std::unique_ptr<TreeNode> BST::insertHelper(std::unique_ptr<TreeNode> node, int value) {
    if (!node) {
        return std::make_unique<TreeNode>(value);
    }
    if (value < node->value) {
        node->left = insertHelper(std::move(node->left), value);
    } else if (value > node->value) {
        node->right = insertHelper(std::move(node->right), value);
    }
    return node;
}

// Search for a value in the BST
bool BST::search(int value) {
    return searchHelper(root.get(), value);
}

// Helper function to search for a value in the BST
bool BST::searchHelper(const TreeNode* node, int value) const {
    if (!node) {
        return false;
    }
    if (node->value == value) {
        return true;
    } else if (value < node->value) {
        return searchHelper(node->left.get(), value);
    } else {
        return searchHelper(node->right.get(), value);
    }
}

// Perform in-order traversal of the BST
void BST::inOrderTraversal() {
    inOrderTraversalHelper(root.get());
    std::cout << std::endl;
}

// Helper function to perform in-order traversal of the BST
void BST::inOrderTraversalHelper(const TreeNode* node) const {
    if (node) {
        inOrderTraversalHelper(node->left.get());
        std::cout << node->value << " ";
        inOrderTraversalHelper(node->right.get());
    }
}

// Print the structure of the BST
void BST::print() {
    printHelper(root.get(), "", false);
}

// Helper function to print the structure of the BST
void BST::printHelper(const TreeNode* node, std::string indent, bool isRight) const {
    if (node) {
        std::cout << indent;
        if (isRight) {
            std::cout << "R----";
            indent += "   ";
        } else {
            std::cout << "L----";
            indent += "|  ";
        }
        std::cout << node->value << std::endl;
        printHelper(node->left.get(), indent, false);
        printHelper(node->right.get(), indent, true);
    }
}