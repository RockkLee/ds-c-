#include "mst/Edge.h"

Edge::Edge() {
}

Edge::Edge(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2, double weight) {
    this->node1 = node1;
    this->node2 = node2;
    this->weight = weight;
}