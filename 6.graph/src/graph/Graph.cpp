#include <graph/Graph.h>

#include <queue>

Graph::Graph() {
}

std::vector<std::shared_ptr<NodeGraph>> Graph::dft(std::shared_ptr<NodeGraph> startNode) {
    this->result.clear();
    return this->dftHelper(startNode);
}
std::vector<std::shared_ptr<NodeGraph>> Graph::dftHelper(std::shared_ptr<NodeGraph> startNode) {
    startNode->visited = true;
    this->result.push_back(startNode);

    for (auto neighbor : startNode->neighbors) {
        if (!neighbor->visited)
            this->dftHelper(neighbor);
    }

    return this->result;
}

std::vector<std::shared_ptr<NodeGraph>> Graph::bft(std::shared_ptr<NodeGraph> startNode) {
    this->result.clear();
    return this->bftHelper(startNode);
}
std::vector<std::shared_ptr<NodeGraph>> Graph::bftHelper(std::shared_ptr<NodeGraph> startNode) {
    auto queue = std::queue<std::shared_ptr<NodeGraph>>();
    startNode->visited = true;
    queue.push(startNode);

    while (!queue.empty()) {
        std::shared_ptr<NodeGraph> firstNode = queue.front();
        queue.pop();

        this->result.push_back(firstNode);
        
        for (auto neighbor : firstNode->neighbors) {
            if (!neighbor->visited) {
                neighbor->visited = true;
                queue.push(neighbor);
            }
        }
    }

    return this->result;
}