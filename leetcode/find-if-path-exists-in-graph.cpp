class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (n == 1) return true;

        // Construct graph
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // BFS
        queue<int> queue;
        vector<int> visited(n);

        queue.push(source);
        visited[source] = 1;

        while (!queue.empty()) {
            const auto& neighbors = graph[queue.front()];
            queue.pop();
            for (const auto& neighbor : neighbors) {
                if (neighbor == destination) return true;
                if (visited[neighbor] == 0) {
                    queue.push(neighbor);
                    ++visited[neighbor];
                }
            }

        }

        return false;
    }
};