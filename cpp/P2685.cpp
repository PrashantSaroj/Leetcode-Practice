#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> parent, size;

    int find(int node) {
        if (parent[node] == node) return node;
        // do path compression
        parent[node] = find(parent[node]);
        return parent[node];
    }

    void swap(int& i1, int& i2) {
        i1 = i1 ^ i2;
        i2 = i1 ^ i2;
        i1 = i1 ^ i2;
    }

    void merge(int node1, int node2) {
        int root1 = find(node1), root2 = find(node2);
        if (root1 == root2) return;
        // union by rank
        if (size[root1] < size[root2]) swap(root1, root2);
        parent[root2] = root1;
        size[root1] += root2;
    }

    inline bool edgeInSet(set<pair<int, int>>& edges, int u, int v) {
        return (edges.find({u, v}) != edges.end()) || (edges.find({v, u}) != edges.end());
    }

    bool isCompleteComponent(set<pair<int, int>>& edges, vector<int>& component) {
        int compSize = component.size();
        for (int i = 0; i < compSize; i++) {
            for (int j = i + 1; j < compSize; j++) {
                if (!edgeInSet(edges, component[i], component[j])) return false;
            }
        }
        return true;
    }

    set<pair<int, int>> createEdgeSet(vector<vector<int>>& edges) {
        set<pair<int, int>> edgeSet;
        for (auto& e : edges) {
            edgeSet.insert({e[0], e[1]});
        }
        return edgeSet;
    }

   public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            size[i] = 0;
            parent[i] = i;
        }

        for (auto& e : edges) {
            merge(e[0], e[1]);
        }

        unordered_map<int, vector<int>> root2Nodes;
        for (int i = 0; i < n; i++) {
            root2Nodes[find(i)].push_back(i);
        }

        int completeComponents = 0;
        // for faster checks
        set<pair<int, int>> edgeSet = createEdgeSet(edges);

        for (auto& [root, component] : root2Nodes) {
            completeComponents += isCompleteComponent(edgeSet, component);
        }
        return completeComponents;
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> testCases = {
        {6, {{0, 1}, {0, 2}, {1, 2}, {3, 4}}},
        {6, {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}}},
    };

    for (auto& t : testCases) {
        cout << Solution().countCompleteComponents(t.first, t.second) << endl;
    }
}
