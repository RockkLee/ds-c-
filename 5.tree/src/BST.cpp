#include "BST.h"
#include <iostream>


BST::BST() {
}

void BST::insert(std::shared_ptr<Node> target) {
    if (root == nullptr) {
        root = target;
        return;
    }
    std::shared_ptr<Node> cur = root;
    while (true) {
        if (target->data < cur->data) {
            if (cur->left == nullptr) {
                cur->left = target;
                return;
            }
            cur = cur->left;
        } else {
            if (cur->right == nullptr) {
                cur->right = target;
                return;
            }
            cur = cur->right;
        }
    }
}

// left, root, right
void BST::preOrder(std::shared_ptr<Node> cur) {
    if (cur == nullptr) {
        return;
    }
    std::cout << cur->data << ",";
    preOrder(cur->left);
    preOrder(cur->right);
}

// root, left, right
void BST::inOrder(std::shared_ptr<Node> cur) {
    if (cur == nullptr) {
        return;
    }
    inOrder(cur->left);
    std::cout << cur->data << ",";
    inOrder(cur->right);
}

// left, right, root
void BST::postOrder(std::shared_ptr<Node> cur) {
    if (cur == nullptr) {
        return;
    }
    postOrder(cur->left);
    postOrder(cur->right);
    std::cout << cur->data << ",";
}

std::shared_ptr<Node> BST::searchRecursively(int target) {
    return searchHelper(root, target);
}
std::shared_ptr<Node> BST::searchHelper(std::shared_ptr<Node> cur, int target) {
    if (cur == nullptr)
        return cur;
    if (cur->data == target)
        return cur;
    
    if (target < cur->data)
        return searchHelper(cur->left, target);
    else
        return searchHelper(cur->right, target);
}

std::shared_ptr<Node> BST::searchIteratively(int target) {
    if (root == nullptr) {
        return nullptr;
    }
    std::shared_ptr<Node> cur = root;
    while (cur != nullptr) {
        if (cur->data == target)
            return cur;
        if (target < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return nullptr;
}

void BST::bft() {
    if (root == nullptr) {
        return;
    }
    bftQueue.push(root);
    while (!bftQueue.empty()) {
        std::shared_ptr<Node> cur = bftQueue.front();
        std::cout << cur->data << ",";
        bftQueue.pop();
        if (cur->left != nullptr)
            bftQueue.push(cur->left);
        if (cur->right != nullptr)
            bftQueue.push(cur->right);
    }
}


void BST::deleteNode(int target) {
    deleteNodeHelper(root, target);
}
std::shared_ptr<Node> BST::deleteNodeHelper(std::shared_ptr<Node> cur, int target) {
    if (cur == nullptr)
        return cur;
    if (cur->data == target) {
        if (cur->left == nullptr && cur->right == nullptr) {
            return nullptr;
        } else if (cur->left == nullptr) {
            return cur->right;
        } else if (cur->right == nullptr) {
            return cur->left;
        }
    }

    if (target < cur->data)
        return deleteNodeHelper(cur->left, target);
    else
        return deleteNodeHelper(cur->right, target);
}