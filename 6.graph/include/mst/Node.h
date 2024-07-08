#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <memory>

// prevent the dependency cycle
// #include <mst/Edge.h>
class Edge;

class Node {
private:
    /* data */
public:
    Node();
    Node(std::string value);

    std::string value;
    bool visited = false;
    std::vector<std::shared_ptr<Edge>> edges;

    void addEdge(std::shared_ptr<Edge> edge);
};

#endif //NODE_H