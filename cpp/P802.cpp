#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
    int numNodes;
    vector<int> visited, isSafe;

    void dfs(vector<vector<int>>& graph, int s) {
        if (visited[s]) {
            isSafe[s] = false;
            return;
        }

        visited[s] = true;
        for (auto& neighbor : graph[s])
            if (!visited[neighbor]) dfs(graph, neighbor);

        bool curSafe = true;
        for (auto& neighbor : graph[s])
            if (!isSafe[neighbor]) {
                curSafe = false;
                break;
            }
        isSafe[s] = curSafe;
    }

   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        numNodes = graph.size();
        isSafe = vector<int>(numNodes, false);
        visited = vector<int>(numNodes, false);

        for (int i = 0; i < numNodes; i++)
            if (!visited[i]) dfs(graph, i);

        vector<int> safe;
        for (int i = 0; i < numNodes; i++)
            if (isSafe[i]) safe.push_back(i);
        return safe;
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}},
        {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}},
    };

    for (auto& t : testCases)
        printVector(Solution().eventualSafeNodes(t));
    return 0;
}
