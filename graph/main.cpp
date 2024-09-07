#include <string>

#include "graph_algo.hpp"

int main() {
    WeightedDigraph<string, int> g;
    string pranay = "Pranay";
    string neo = "Neo";
    string ray = "Ray";
    string shaurya = "Shaurya";
    string harish = "Harish";
    string arnav = "Arnav";
    string amnicius = "Amnicius";

    g.addEdge(pranay, ray, 1);
    g.addEdge(pranay, neo, 1);
    g.addEdge(pranay, shaurya, 1);
    g.addEdge(pranay, harish, 1);
    g.addEdge(pranay, arnav, 1);
    g.addEdge(ray, neo, 1);
    g.addEdge(ray, amnicius, 1);
    g.addEdge(shaurya, harish, 1);

    g.printGraph();
    cout << endl;
    BFS(g, pranay);
    DFS(g, pranay);

    return 0;
}