#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

typedef pair<int, pair<int, int>> cell;
class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<pair<int, int>> getUnvisitedNeighbors(int i, int j, int nRow, int nCol, vector<vector<bool>>& visited) {
        vector<pair<int, int>> neighbors;
        for (auto& [dx, dy] : dirs) {
            int cx = i + dx, cy = j + dy;
            if (cx >= 0 && cx < nRow && cy >= 0 && cy < nCol && !visited[cx][cy]) {
                neighbors.push_back({cx, cy});
            }
        }
        return neighbors;
    }

   public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        int nRow = grid.size(), nCol = grid[0].size();
        vector<vector<bool>> visited(nRow, vector<bool>(nCol, false));
        priority_queue<cell, vector<cell>, greater<cell>> minHeapCell;
        minHeapCell.push({grid[0][0], {0, 0}});

        // sort the queries, preserving indices
        vector<pair<int, int>> indexedQueries(k);
        for (int i = 0; i < k; i++) {
            indexedQueries[i] = {queries[i], i};
        }
        sort(indexedQueries.begin(), indexedQueries.end());

        // process queries
        vector<int> qRes(k);
        int visitedCount = 0;
        for (auto& [qVal, i] : indexedQueries) {
            while (!minHeapCell.empty()) {
                cell minCell = minHeapCell.top();
                int cx = minCell.second.first, cy = minCell.second.second;
                if (minCell.first >= qVal) break;

                minHeapCell.pop();
                if (visited[cx][cy]) continue;
                visitedCount += (visited[cx][cy] = true);
                for (auto& [nx, ny] : getUnvisitedNeighbors(cx, cy, nRow, nCol, visited)) {
                    minHeapCell.push({grid[nx][ny], {nx, ny}});
                }
            }
            qRes[i] = visitedCount;
        }
        return qRes;
    }
};

int main() {
    vector<pair<vector<vector<int>>, vector<int>>> testCases = {
        {{{1, 2, 3}, {2, 5, 7}, {3, 5, 1}}, {5, 6, 2}},
        {{{5, 2, 1}, {1, 1, 2}}, {3}},
    };

    for (auto& t : testCases) {
        printVector(Solution().maxPoints(t.first, t.second));
    }
}
