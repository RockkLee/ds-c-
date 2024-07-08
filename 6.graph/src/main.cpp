#include <stdio.h>

#include <iostream>
#include <vector>
#include <memory>

#include <mst/Node.h>
#include <mst/Edge.h>
#include <mst/Mst.h>
#include <graph/NodeGraph.h>
#include <graph/Graph.h>

/**
 *        A
 *      / | \
 *    10  |   8
 *   /    |    \
 *  B--6--D--5--C
 * /    / |    /
 * 7   4  3   8
 * |  /   |  /
 * \ /    | /
 *  E--1--F-
 */
void mst() {
    std::shared_ptr<Node> a = std::make_shared<Node>("A");
    std::shared_ptr<Node> b = std::make_shared<Node>("B");
    std::shared_ptr<Node> c = std::make_shared<Node>("C");
    std::shared_ptr<Node> d = std::make_shared<Node>("D");
    std::shared_ptr<Node> e = std::make_shared<Node>("E");
    std::shared_ptr<Node> f = std::make_shared<Node>("F");
    std::shared_ptr<Edge> ab = std::make_shared<Edge>(a, b, 10);
    a->addEdge(ab);
    b->addEdge(ab);
    std::shared_ptr<Edge> ac = std::make_shared<Edge>(a, c, 8);
    a->addEdge(ac);
    c->addEdge(ac);
    std::shared_ptr<Edge> bd = std::make_shared<Edge>(b, d, 6);
    b->addEdge(bd);
    d->addEdge(bd);
    std::shared_ptr<Edge> cd = std::make_shared<Edge>(c, d, 5);
    c->addEdge(cd);
    d->addEdge(cd);
    std::shared_ptr<Edge> be = std::make_shared<Edge>(b, e, 7);
    b->addEdge(be);
    e->addEdge(be);
    std::shared_ptr<Edge> de = std::make_shared<Edge>(d, e, 4);
    d->addEdge(de);
    e->addEdge(de);
    std::shared_ptr<Edge> df = std::make_shared<Edge>(d, f, 3);
    d->addEdge(df);
    f->addEdge(df);
    std::shared_ptr<Edge> ef = std::make_shared<Edge>(e, f, 1);
    e->addEdge(ef);
    f->addEdge(ef);
    std::shared_ptr<Edge> cf = std::make_shared<Edge>(c, f, 8);
    c->addEdge(cf);
    f->addEdge(cf);
    std::vector<std::shared_ptr<Node>> nodes = {a, b, c, d, e, f};

    Mst mst = Mst();
    std::vector<std::shared_ptr<Edge>> result = mst.mstPrimAlgo(a, nodes);
    for (auto edge : result) {
        printf("%s - %s: %f\n", edge->node1->value.c_str(), edge->node2->value.c_str(), edge->weight);
    }

}

void dfsGraph() {
    std::shared_ptr<NodeGraph> a = std::make_shared<NodeGraph>("A");
    std::shared_ptr<NodeGraph> b = std::make_shared<NodeGraph>("B");
    std::shared_ptr<NodeGraph> c = std::make_shared<NodeGraph>("C");
    std::shared_ptr<NodeGraph> d = std::make_shared<NodeGraph>("D");
    std::shared_ptr<NodeGraph> e = std::make_shared<NodeGraph>("E");
    std::shared_ptr<NodeGraph> f = std::make_shared<NodeGraph>("F");
    std::shared_ptr<NodeGraph> g = std::make_shared<NodeGraph>("G");
    std::shared_ptr<NodeGraph> h = std::make_shared<NodeGraph>("H");
    std::shared_ptr<NodeGraph> i = std::make_shared<NodeGraph>("I");
    std::shared_ptr<NodeGraph> j = std::make_shared<NodeGraph>("J");
    std::shared_ptr<NodeGraph> k = std::make_shared<NodeGraph>("K");
    std::shared_ptr<NodeGraph> l = std::make_shared<NodeGraph>("L");
    std::shared_ptr<NodeGraph> m = std::make_shared<NodeGraph>("M");
    a->addNeighbor(e);
    a->addNeighbor(f);
    b->addNeighbor(d);
    c->addNeighbor(d);
    d->addNeighbor(b);
    d->addNeighbor(c);
    d->addNeighbor(e);
    d->addNeighbor(i);
    e->addNeighbor(a);
    e->addNeighbor(d);
    e->addNeighbor(f);
    e->addNeighbor(i);
    f->addNeighbor(a);
    f->addNeighbor(e);
    f->addNeighbor(i);
    g->addNeighbor(h);
    g->addNeighbor(i);
    h->addNeighbor(g);
    h->addNeighbor(i);
    h->addNeighbor(l);
    i->addNeighbor(d);
    i->addNeighbor(e);
    i->addNeighbor(f);
    i->addNeighbor(g);
    i->addNeighbor(h);
    i->addNeighbor(j);
    i->addNeighbor(k);
    i->addNeighbor(m);
    j->addNeighbor(i);
    j->addNeighbor(m);
    k->addNeighbor(i);
    k->addNeighbor(l);
    k->addNeighbor(m);
    l->addNeighbor(h);
    l->addNeighbor(k);
    m->addNeighbor(i);
    m->addNeighbor(j);
    m->addNeighbor(k);

    Graph graph = Graph();
    std::vector<std::shared_ptr<NodeGraph>> result = graph.dft(a);
    for (auto node : result)
        std::cout << node->value << ", ";
    std::cout << std::endl;
}
void bfsGraph() {
    std::shared_ptr<NodeGraph> a = std::make_shared<NodeGraph>("A");
    std::shared_ptr<NodeGraph> b = std::make_shared<NodeGraph>("B");
    std::shared_ptr<NodeGraph> c = std::make_shared<NodeGraph>("C");
    std::shared_ptr<NodeGraph> d = std::make_shared<NodeGraph>("D");
    std::shared_ptr<NodeGraph> e = std::make_shared<NodeGraph>("E");
    std::shared_ptr<NodeGraph> f = std::make_shared<NodeGraph>("F");
    std::shared_ptr<NodeGraph> g = std::make_shared<NodeGraph>("G");
    std::shared_ptr<NodeGraph> h = std::make_shared<NodeGraph>("H");
    std::shared_ptr<NodeGraph> i = std::make_shared<NodeGraph>("I");
    std::shared_ptr<NodeGraph> j = std::make_shared<NodeGraph>("J");
    std::shared_ptr<NodeGraph> k = std::make_shared<NodeGraph>("K");
    std::shared_ptr<NodeGraph> l = std::make_shared<NodeGraph>("L");
    std::shared_ptr<NodeGraph> m = std::make_shared<NodeGraph>("M");
    a->addNeighbor(e);
    a->addNeighbor(f);
    b->addNeighbor(d);
    c->addNeighbor(d);
    d->addNeighbor(b);
    d->addNeighbor(c);
    d->addNeighbor(e);
    d->addNeighbor(i);
    e->addNeighbor(a);
    e->addNeighbor(d);
    e->addNeighbor(f);
    e->addNeighbor(i);
    f->addNeighbor(a);
    f->addNeighbor(e);
    f->addNeighbor(i);
    g->addNeighbor(h);
    g->addNeighbor(i);
    h->addNeighbor(g);
    h->addNeighbor(i);
    h->addNeighbor(l);
    i->addNeighbor(d);
    i->addNeighbor(e);
    i->addNeighbor(f);
    i->addNeighbor(g);
    i->addNeighbor(h);
    i->addNeighbor(j);
    i->addNeighbor(k);
    i->addNeighbor(m);
    j->addNeighbor(i);
    j->addNeighbor(m);
    k->addNeighbor(i);
    k->addNeighbor(l);
    k->addNeighbor(m);
    l->addNeighbor(h);
    l->addNeighbor(k);
    m->addNeighbor(i);
    m->addNeighbor(j);
    m->addNeighbor(k);

    Graph graph;
    std::vector<std::shared_ptr<NodeGraph>> result = graph.bft(a);
    for (auto node : result)
        std::cout << node->value << ", ";
    std::cout << std::endl;
}

int main(int, char**){
    printf("Hello, from graph!\n");

    std::cout << "mst:" << std::endl;
    mst();
    std::cout << std::endl;
    
    std::cout << "dfs:" << std::endl;
    dfsGraph();
    std::cout << std::endl;
    
    std::cout << "bfs:" << std::endl;
    bfsGraph();
    std::cout << std::endl;

    return 0;
}
