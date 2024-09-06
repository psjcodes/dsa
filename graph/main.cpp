#include <string>

#include "Graph.hpp"

int main() {
    SimpleGraph<string> g;
    g.addEdge("Pranay", "Neo");
    g.addEdge("Ray", "Neo");
    g.addEdge("Pranay", "Ray");
    g.addEdge("Pranay", "Shaurya");
    g.addEdge("Ray", "Shaurya");
    g.printGraph();
    g.removeEdge("Ray", "Pranay");
    g.printGraph();

    WeightedDigraph<int, double> dg;
    dg.addEdge(0, 1, 2.5);
    dg.addEdge(0, 2, 5.6);
    dg.addEdge(1, 2, 3.1);
    dg.printGraph();
    dg.removeEdge(0, 1);
    dg.printGraph();

    AdjMatrixGraph<int> mg(5);
    mg.addEdge(0, 1, 3);
    mg.addEdge(0, 4, 2);
    mg.addEdge(1, 4, 7);
    mg.printGraph();
    mg.removeEdge(1, 4);
    mg.printGraph();

    return 0;
}