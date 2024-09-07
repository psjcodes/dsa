#include <queue>

#include "Graph.hpp"

template <typename KeyType, typename ValueType>
void BFS(const Graph<KeyType, ValueType>& graph, const KeyType& startNode) {
    cout << "BFS" << endl << "---" << endl;

    queue<KeyType> queue;
    unordered_map<KeyType, bool> visited;

    queue.push(startNode);
    visited[startNode] = true;

    int nodeCount = 0;
    while (!queue.empty()) {
        ++nodeCount;
        KeyType currNode = queue.front();
        queue.pop();

        cout << "Node " << nodeCount << " visited: " << currNode << endl;

        vector<KeyType> neighbors = graph.getNeighbors(currNode);
        for (const auto& neighbor : neighbors) {
            if (!visited[neighbor]) {
                queue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
};

template <typename KeyType, typename ValueType>
void DFSHelper(const Graph<KeyType, ValueType>& graph, const KeyType& currNode,
               unordered_map<KeyType, bool>& visited, int& nodeCount) {
    ++nodeCount;
    visited[currNode] = true;

    cout << "Node " << nodeCount << " visited: " << currNode << endl;

    vector<KeyType> neighbors = graph.getNeighbors(currNode);
    for (const auto& neighbor : neighbors) {
        if (!visited[neighbor]) DFSHelper(graph, neighbor, visited, nodeCount);
    }
};

template <typename KeyType, typename ValueType>
void DFS(const Graph<KeyType, ValueType>& graph, const KeyType& startNode) {
    unordered_map<KeyType, bool> visited;
    int nodeCount = 0;

    cout << "DFS" << endl << "---" << endl;

    DFSHelper(graph, startNode, visited, nodeCount);
};