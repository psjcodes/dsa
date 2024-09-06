#pragma once
#include <iostream>
#include <list>
#include <optional>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// Graph interface
template <typename KeyType, typename ValueType>
class Graph {
public:
    Graph() = default;
    virtual ~Graph() = default;
    virtual void addEdge(const KeyType& src, const KeyType& dest,
                         const optional<ValueType> weight = nullopt) = 0;
    virtual void removeEdge(const KeyType& src, const KeyType& dest) = 0;
    virtual void printGraph() const = 0;
    virtual int getNumNodes() const = 0;
    virtual vector<KeyType> getNeighbors(const KeyType& node) const = 0;
};

// Abstract base class for graphs represented by adjacency list
template <typename KeyType, typename ValueType>
class AdjListGraph : public Graph<KeyType, ValueType> {
protected:
    unordered_map<KeyType, list<ValueType>> adjList;

public:
    AdjListGraph() = default;
    virtual ~AdjListGraph() = default;
    virtual void addEdge(const KeyType& src, const KeyType& dest,
                         const optional<ValueType> weight = nullopt) = 0;
    virtual void removeEdge(const KeyType& src, const KeyType& dest) = 0;
    virtual int getNumNodes() const { return adjList.size(); }
    vector<KeyType> getNeighbors(const KeyType& node) const {
        try {
            vector<KeyType> neighbors(adjList.at(node).begin(), adjList.at(node).end());
            return neighbors;
        } catch (const out_of_range& e) {
            cerr << "Node " << node << "is not in the graph!" << endl;
            return {};
        }
    };
    virtual void printGraph() const = 0;
};

// Unweighted, undirected "simple" graph
template <typename KeyType>
class SimpleGraph : public AdjListGraph<KeyType, KeyType> {
public:
    SimpleGraph() = default;
    ~SimpleGraph() = default;
    void addEdge(const KeyType& src, const KeyType& dest,
                 optional<KeyType> weight = nullopt) override;
    void removeEdge(const KeyType& src, const KeyType& dest) override;
    void printGraph() const override;
};

template <typename KeyType, typename ValueType>
class WeightedDigraph : public AdjListGraph<KeyType, ValueType> {
private:
    unordered_map<KeyType, list<pair<KeyType, ValueType>>> adjList;

public:
    WeightedDigraph() = default;
    ~WeightedDigraph() = default;
    void addEdge(const KeyType& src, const KeyType& dest,
                 const optional<ValueType> weight) override;
    void removeEdge(const KeyType& src, const KeyType& dest) override;
    void printGraph() const override;
};

template <typename ValueType>
class AdjMatrixGraph : public Graph<int, ValueType> {
private:
    vector<vector<ValueType>> adjMatrix;
    int maxNodes;

public:
    AdjMatrixGraph(int maxNodes);
    ~AdjMatrixGraph() = default;
    bool isValidNode(const int& node) const;
    void addEdge(const int& src, const int& dest, const optional<ValueType> weight) override;
    void removeEdge(const int& src, const int& dest) override;
    void printGraph() const override;
    int getNumNodes() const override;
    vector<int> getNeighbors(const int& node) const override;
};