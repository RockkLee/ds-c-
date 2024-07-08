#ifndef EDGE_H
#define EDGE_H

#include <memory>

#include <mst/Node.h>

class Edge {
private:
public:
    Edge();
    Edge(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2, double weight);

    std::shared_ptr<Node> node1;
    std::shared_ptr<Node> node2;
    double weight;
};

#endif //EDGE_H