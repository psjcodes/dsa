#include "Graph.hpp"
#include <string>

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

    return 0;
}