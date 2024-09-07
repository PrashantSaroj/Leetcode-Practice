#include <bits/stdc++.h>

#include "utils/Dijkstra.cpp"

using namespace std;

class Solution {
   public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target) {
        vector<edge> adj[n];

        for (auto &e : edges) {
            if (e[2] != -1) {
                adj[e[0]].push_back({e[2], e[1]});
                adj[e[1]].push_back({e[2], e[0]});
            }
        }

        int shortestDist = Dijkstra().shortestPath(n, source, destination, adj);

        if (shortestDist < target) {
            return {};
        }

        bool solFind = (shortestDist == target);

        for (auto &e : edges) {
            if (e[2] == -1) {
                e[2] = solFind ? INF : 1;

                adj[e[0]].push_back({e[2], e[1]});
                adj[e[1]].push_back({e[2], e[0]});

                if (!solFind) {
                    int newShortestPath = Dijkstra().shortestPath(n, source, destination, adj);
                    if (newShortestPath <= target) {
                        solFind = true;
                        e[2] += target - newShortestPath;
                    }
                }
            }
        }
        return solFind ? edges : vector<vector<int>>{};
    }
};

int main() {
    int n = 5, target = 5;
    int source = 0, destination = 1;
    vector<vector<int>> edges = {{4, 1, -1}, {2, 0, -1}, {0, 3, -1}, {4, 3, -1}};

    vector<vector<int>> modEdges = Solution().modifiedGraphEdges(n, edges, source, destination, target);

    for (auto &e : modEdges) {
        cout << e[0] << " " << e[1] << " " << e[2] << endl;
    }

    return 0;
}
