#include "mst/Node.h"

Node::Node() {
}

Node::Node(std::string value) {
    this->value = value;
}

void Node::addEdge(std::shared_ptr<Edge> edge) {
    edges.push_back(edge);
}