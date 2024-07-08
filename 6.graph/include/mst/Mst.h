#ifndef MST_H
#define MST_H

#include <vector>
#include <memory>

#include <mst/Node.h>
#include <mst/Edge.h>

class Mst { // Minimum Spanning Tree
private:
    std::shared_ptr<Edge> findBestEdge(std::vector<std::shared_ptr<Edge>>);
public:
    std::vector<std::shared_ptr<Edge>> mstPrimAlgo(std::shared_ptr<Node>,  std::vector<std::shared_ptr<Node>>);
};

#endif //MST_H