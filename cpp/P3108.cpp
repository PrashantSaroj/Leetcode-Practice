#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"

using namespace std;

struct Neighbor {
    int node, weight;
};

class Graph {
    vector<vector<Neighbor>> adj;

    vector<int> node2Component;
    vector<int> component2walk;

    inline int getComponent(int node) { return node2Component[node]; }
    inline int getMinCostWalk(int component) { return component2walk[component]; }

    void bfsAndProcess(int src, vector<int>& visited, int comp) {
        unsigned int walkCost = -1;
        queue<int> bfsQ({src});
        visited[src] = true;
        // do bfs and compute "AND"
        while (!bfsQ.empty()) {
            int curr = bfsQ.front();
            bfsQ.pop();
            node2Component[curr] = comp;

            for (auto& [neighbor, weight] : adj[curr]) {
                walkCost &= weight;
                if (!visited[neighbor]) {
                    bfsQ.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        component2walk.push_back(walkCost);
    }

   public:
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        node2Component.resize(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int curComponent = 0;
        vector<int> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfsAndProcess(i, visited, curComponent++);
            }
        }
    }

    int processQuery(vector<int>& query) {
        int comp1 = getComponent(query[0]);
        int comp2 = getComponent(query[1]);
        return comp1 == comp2 ? getMinCostWalk(comp1) : -1;
    }
};

class Solution {
   public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        Graph g(n, edges);
        vector<int> walks;

        for (auto& q : query) {
            walks.push_back(g.processQuery(q));
        }
        return walks;
    }
};

int main() {
    vector<tuple<int, vector<vector<int>>, vector<vector<int>>>> testCases = {
        {5, {{0, 1, 7}, {1, 3, 7}, {1, 2, 1}}, {{0, 3}, {3, 4}}},
        {3, {{0, 2, 7}, {0, 1, 15}, {1, 2, 6}, {1, 2, 1}}, {{1, 2}}},
    };

    for (auto& t : testCases) {
        printVector(Solution().minimumCost(get<0>(t), get<1>(t), get<2>(t)));
    }
}
