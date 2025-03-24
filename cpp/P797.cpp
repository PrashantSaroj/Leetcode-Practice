#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
    int target;
    vector<vector<int>> graph;
    vector<vector<int>> paths;

    void helper(int src, vector<int>& currPath) {
        if (src == target) {
            paths.push_back(vector<int>(currPath.begin(), currPath.end()));
            return;
        }

        for (int neighborNode : graph[src]) {
            currPath.push_back(neighborNode);
            helper(neighborNode, currPath);
            currPath.pop_back();
        }
    }

   public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->graph = graph;
        this->target = graph.size() - 1;
        // fill all the paths recursively
        vector<int> curPath = {0};
        helper(0, curPath);

        return paths;
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{{1, 2}, {3}, {3}, {}}},
        {{{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}}},
    };
    for (auto& t : testCases) {
        printVecOfVector(Solution().allPathsSourceTarget(t));
    }
}
