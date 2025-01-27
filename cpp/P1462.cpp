#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

typedef tuple<int, vector<vector<int>>, vector<vector<int>>> tc_type;

class Solution {
    vector<bool> visited;
    vector<vector<int>> graph;
    vector<unordered_set<int>> paths;

    void fillPathDfs(int s) {
        if (visited[s]) return;

        vector<int>& neighbors = graph[s];
        for (int n : neighbors)
            fillPathDfs(n);

        for (int n : neighbors) {
            paths[s].insert(n);
            paths[s].insert(paths[n].begin(), paths[n].end());
        }
        visited[s] = true;
    }

   public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        graph.resize(numCourses);
        paths.resize(numCourses);
        visited = vector<bool>(numCourses, false);

        for (auto& prereq : prerequisites)
            graph[prereq[1]].push_back(prereq[0]);

        for (int i = 0; i < numCourses; i++)
            fillPathDfs(i);

        int queriesCount = queries.size();
        vector<bool> result(queriesCount, false);
        for (int i = 0; i < queriesCount; i++) {
            if (paths[queries[i][1]].count(queries[i][0])) result[i] = true;
        }
        return result;
    }
};

int main() {
    vector<tc_type> testCases = {
        {2, {{1, 0}}, {{0, 1}, {1, 0}}},
        {2, {}, {{1, 0}, {0, 1}}},
        {3, {{1, 2}, {1, 0}, {2, 0}}, {{1, 0}, {1, 2}}},
    };

    for (auto& t : testCases)
        printVector(Solution().checkIfPrerequisite(get<0>(t), get<1>(t), get<2>(t)));

    return 0;
}
