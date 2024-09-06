#include "Graph.h"
#include <algorithm>
#include <cmath>

template <typename KeyType>
void SimpleGraph<KeyType>::addEdge(const KeyType& src, const KeyType& dest, optional<KeyType> weight) {
    this->adjList[src].push_back(dest);
    this->adjList[dest].push_back(src);
};

template <typename KeyType>
void SimpleGraph<KeyType>::removeEdge(const KeyType& src, const KeyType& dest) {
    this->adjList[src].remove(dest);
    this->adjList[dest].remove(src);
};

template <typename KeyType>
void SimpleGraph<KeyType>::printGraph() const {
    for (const auto& pair : this->adjList) {
        const auto& node = pair.first;
        const auto& neighbors = pair.second;
        
        cout << node << " -> ";

        for (const auto& neighbor : neighbors) {
            cout << neighbor << " ";
        }

        cout << endl;
    }
};

template <typename KeyType, typename ValueType>
void WeightedDigraph<KeyType, ValueType>::addEdge(const KeyType& src, const KeyType& dest, const optional<ValueType> weight) {
    adjList[src].push_back(make_pair(dest, *weight));
};

template <typename KeyType, typename ValueType>
void WeightedDigraph<KeyType, ValueType>::removeEdge(const KeyType& src, const KeyType& dest) {
    auto& neighbors = adjList[src];
    for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
        if (it->first == dest) {
            neighbors.erase(it);
            break;
        }
    }
};

template <typename KeyType, typename ValueType>
void WeightedDigraph<KeyType, ValueType>::printGraph() const {
    for (const auto& pair : adjList) {
        const auto& node = pair.first;
        const auto& neighbors = pair.second;

        cout << node << " -> ";

        for (const auto& neighbor : neighbors) {
            cout << "[" << neighbor.first << ", " << neighbor.second << "] ";
        }
        
        cout << endl;
    }
};

template <typename ValueType>
AdjMatrixGraph<ValueType>::AdjMatrixGraph(int maxNodes) {
    adjMatrix.resize(maxNodes, vector<ValueType>(maxNodes, 0));
    this->maxNodes = maxNodes;
};

template <typename ValueType>
bool AdjMatrixGraph<ValueType>::isValidNode(const int& node) const {
    return node >= 0 && node < maxNodes;
};

template <typename ValueType>
void AdjMatrixGraph<ValueType>::addEdge(const int& src, const int& dest, const optional<ValueType> weight) {
    if (isValidNode(src) && isValidNode(dest)) {
        adjMatrix[src][dest] = *weight;
    } else {
        cerr << "The src or dest node is out of bounds!" << endl;
    }
};

template <typename ValueType>
void AdjMatrixGraph<ValueType>::removeEdge(const int& src, const int& dest) {
    if (isValidNode(src) && isValidNode(dest)) {
        adjMatrix[src][dest] = 0;
    } else {
        cerr << "The src or dest node is out of bounds!" << endl;
    } 
};

template <typename ValueType>
void AdjMatrixGraph<ValueType>::printGraph() const {
    for (int node = 0; node < maxNodes; ++node) {
        for (int neighbor = 0; neighbor < maxNodes; ++neighbor) {
            cout << adjMatrix[node][neighbor];
        }
        cout << endl;
    }
};

template <typename ValueType>
int AdjMatrixGraph<ValueType>::getNumNodes() const {
    int numNodes = 0;
    for (int i = 0; i < maxNodes; ++i) {
        for (int j = i; j < maxNodes; ++j) {
            if (fabs(adjMatrix[i][j] > 1e-9)) {
                ++numNodes;
                break;
            }
        }
    }
    return numNodes;
};

template <typename ValueType>
vector<int> AdjMatrixGraph<ValueType>::getNeighbors(const int& node) const {
    if (isValidNode(node)) {
        return adjMatrix[node];
    } else {
        cerr << "Node " << node << "is out of bounds!" << endl;
        return {};
    }
};