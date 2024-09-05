#include "Graph.h"

void SimpleGraph::addEdge(int src, int dest, int weight = 1) {

};

void SimpleGraph::removeEdge(int src, int dest) {

};

void SimpleGraph::printGraph() const {

};

void WeightedDigraph::addEdge(int src, int dest, int weight) {

};

void WeightedDigraph::removeEdge(int src, int dest) {

};

void WeightedDigraph::printGraph() const {

};

AdjMatrixGraph::AdjMatrixGraph(int n) {
    adjMatrix.resize(n, vector<int>(n, 0));
};

void AdjMatrixGraph::addEdge(int src, int dest, int weight) {

};

void AdjMatrixGraph::removeEdge(int src, int dest) {

};

void AdjMatrixGraph::printGraph() const {

};
