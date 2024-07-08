#include "graph/NodeGraph.h"

NodeGraph::NodeGraph() {
}

NodeGraph::NodeGraph(std::string value) {
    this->value = value;
}

void NodeGraph::addNeighbor(std::shared_ptr<NodeGraph> neighbor) {
    neighbors.push_back(neighbor);
}