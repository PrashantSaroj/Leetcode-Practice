#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

#define MODULAR 1000000007
#define neighbor pair<int, int>

class Solution {
    vector<int> dist;
    vector<int> nSpt;
    vector<vector<neighbor>> adj;

    void initGraph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        dist.resize(n, INT_MAX);
        nSpt.resize(n, INT_MIN);
        nSpt[0] = 1;
    }

    int countShortestPaths(int target) {
        if (nSpt[target] != INT_MIN) return nSpt[target];

        int shortestPaths = 0;
        for (auto& [w, neiNode] : adj[target]) {
            if (dist[neiNode] + w == dist[target]) {
                shortestPaths += countShortestPaths(neiNode);
                shortestPaths %= MODULAR;
            }
        }
        nSpt[target] = shortestPaths;
        return shortestPaths;
    }

    void dijkstra(int src = 0) {
        // mark src as 0 and do dijkstra
        dist[src] = 0;
        priority_queue<neighbor, vector<neighbor>, greater<neighbor>> minHeap;
        minHeap.push({0, src});

        while (!minHeap.empty()) {
            auto [curDist, curNode] = minHeap.top();
            minHeap.pop();

            for (auto& [w, neiNode] : adj[curNode]) {
                int newDist = dist[curNode] + w;
                if (newDist < dist[neiNode]) {
                    dist[neiNode] = newDist;
                    minHeap.push({newDist, neiNode});
                }
            }
        }
    }

   public:
    int countPaths(int n, vector<vector<int>>& roads) {
        initGraph(n, roads);
        // fill shortest paths in dist
        dijkstra();
        return countShortestPaths(n - 1);
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> testCases = {
        {7, {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}}},
        {2, {{1, 0, 10}}},
    };

    for (auto& t : testCases) {
        cout << Solution().countPaths(t.first, t.second) << endl;
    }
}
