#ifndef NODEGRAPH_H
#define NODEGRAPH_H

#include <string>
#include <vector>
#include <memory>

class NodeGraph {
private:
public:
    NodeGraph();
    NodeGraph(std::string value);

    std::string value;
    bool visited = false;
    std::vector<std::shared_ptr<NodeGraph>> neighbors;

    void addNeighbor(std::shared_ptr<NodeGraph> neighbor);
};

#endif //NODEGRAPH_H