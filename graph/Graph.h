#pragma once
#include <list>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>

using namespace std;

class Graph {
public:
    Graph() = default;
    virtual ~Graph() = default;
    virtual void addEdge(int src, int dest, int weight) = 0;
    virtual void removeEdge(int src, int dest) = 0;
    virtual void printGraph() const = 0;
};

class SimpleGraph : public Graph {
public:
    SimpleGraph() = default;
    ~SimpleGraph() = default;
    void addEdge(int src, int dest, int weight = 1) override;
    void removeEdge(int src, int dest) override;
    void printGraph() const override;

private:
    unordered_map<int, list<int>> adjList;
};

class WeightedDigraph : public Graph {
public:
    WeightedDigraph() = default;
    ~WeightedDigraph() = default;
    void addEdge(int src, int dest, int weight) override;
    void removeEdge(int src, int dest) override;
    void printGraph() const override;

private:
    unordered_map<int, list<pair<int, int>>> adjList;
};

class AdjMatrixGraph : public Graph {
public:
    AdjMatrixGraph(int n);
    ~AdjMatrixGraph() = default;
    void addEdge(int src, int dest, int weight) override;
    void removeEdge(int src, int dest) override;
    void printGraph() const override;

private:
    vector<vector<int>> adjMatrix;
};