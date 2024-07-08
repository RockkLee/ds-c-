#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <memory>

#include <graph/NodeGraph.h>

class Graph {
private:
    std::vector<std::shared_ptr<NodeGraph>> result;
    std::vector<std::shared_ptr<NodeGraph>> dftHelper(std::shared_ptr<NodeGraph> startNode);
    std::vector<std::shared_ptr<NodeGraph>> bftHelper(std::shared_ptr<NodeGraph> startNode);
public:
    Graph(/* args */);

    std::vector<std::shared_ptr<NodeGraph>> dft(std::shared_ptr<NodeGraph> startNode);
    std::vector<std::shared_ptr<NodeGraph>> bft(std::shared_ptr<NodeGraph> startNode);
};

#endif //GRAPH_H