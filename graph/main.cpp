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

    return 0;
}