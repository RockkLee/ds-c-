#include "mst/Mst.h"

#include <vector>
#include <memory>
#include <algorithm>

#include <mst/Node.h>
#include <mst/Edge.h>


std::vector<std::shared_ptr<Edge>> Mst::mstPrimAlgo(std::shared_ptr<Node> startNode, std::vector<std::shared_ptr<Node>> allNodes) {
    std::vector<std::shared_ptr<Edge>> candidateEdges;
    std::vector<std::shared_ptr<Edge>> mstEdges;

    // find the initial candidateEdges from the startNode
    for (auto edge : startNode->edges)
        candidateEdges.push_back(edge);
    
    // find the best edge from the candidateEdges
    std::shared_ptr<Edge> bestEdge = this->findBestEdge(candidateEdges);

    while (bestEdge != nullptr) {
        // add the best edge from the candidateEdges to mstEdges if it has not been visited to avoid cycles
        bestEdge->node1->visited = true;
        bestEdge->node2->visited = true;
        mstEdges.push_back(bestEdge);

        // find the new candidateEdges after adding the best edge to mstEdges
        candidateEdges.clear();
        for (auto node : allNodes) {
            if (!node->visited)
                continue;
            for (auto edge : node->edges) {
                //vector<std::shared_ptr<Edge>>::iterator it = std::find(mstEdges.begin(), mstEdges.end(), edge);
                if (std::find(mstEdges.begin(), mstEdges.end(), edge) == mstEdges.end()) // = !mstEdges.includes(edge)
                    candidateEdges.push_back(edge);
            }
        }

        // find the next best edge
        bestEdge = this->findBestEdge(candidateEdges);
    }

    return mstEdges;
}

std::shared_ptr<Edge> Mst::findBestEdge(std::vector<std::shared_ptr<Edge>> candidateEdges) {
    std::shared_ptr<Edge> bestEdge = nullptr;
    while (bestEdge == nullptr && candidateEdges.size() > 0) {
        bestEdge = candidateEdges[0];
        int idx = 0;
        // find the best edge in the mstEdges
        for (int i = 0; i < candidateEdges.size(); i++) {
            auto edge = candidateEdges[i];
            if (edge->weight < bestEdge->weight) {
                bestEdge = edge;
                idx = i;
            }
        }

        // check if both nodes of the edge are visited
        if (bestEdge->node1->visited && bestEdge->node2->visited) {
            candidateEdges.erase(candidateEdges.begin() + idx);
            bestEdge = nullptr;
        }
    }

    return bestEdge;
}