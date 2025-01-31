#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> islandSize = {0};
    vector<vector<bool>> visited;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector<pair<int, int>> getNeighbors(int i, int j, int N) {
        vector<pair<int, int>> neighbors;
        for (auto d : dirs) {
            int x = i + d.first, y = j + d.second;
            if (x >= 0 && x < N && y >= 0 && y < N)
                neighbors.push_back({x, y});
        }
        return neighbors;
    }

    int getIslandSize(vector<vector<int>>& grid, int i, int j, int currIsland, int N) {
        int size = 1;
        queue<pair<int, int>> bfsQ({{i, j}});
        visited[i][j] = true;
        grid[i][j] = currIsland;

        while (!bfsQ.empty()) {
            auto& [curX, curY] = bfsQ.front();
            auto neighbors = getNeighbors(curX, curY, N);

            for (auto& [neiX, neiY] : neighbors) {
                if (grid[neiX][neiY] && !visited[neiX][neiY]) {
                    size++;
                    bfsQ.push({neiX, neiY});
                    visited[neiX][neiY] = true;
                    grid[neiX][neiY] = currIsland;
                }
            }
            bfsQ.pop();
        }
        return size;
    }

    int combineDistinctNeighborIslands(vector<vector<int>>& grid, int i, int j, int N) {
        int comibinedSum = 1;
        unordered_set<int> seenIslands;

        auto neighbors = getNeighbors(i, j, N);
        for (auto& [x, y] : neighbors) {
            int curIsland = grid[x][y];
            if (curIsland && !seenIslands.count(curIsland)) {
                comibinedSum += islandSize[curIsland];
                seenIslands.insert(curIsland);
            }
        }
        return comibinedSum;
    }

   public:
    int largestIsland(vector<vector<int>>& grid) {
        int currIsland = 1, N = grid.size();
        visited = vector<vector<bool>>(N, vector<bool>(N, 0));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (grid[i][j] && !visited[i][j])
                    islandSize.push_back(getIslandSize(grid, i, j, currIsland++, N));

        int maxSize = islandSize[1];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (!grid[i][j])
                    maxSize = max(maxSize, combineDistinctNeighborIslands(grid, i, j, N));
        return maxSize;
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{1, 0}, {0, 1}},
        {{1, 1}, {1, 0}},
        {{1, 1}, {1, 1}},
    };

    for (auto& t : testCases)
        cout << Solution().largestIsland(t) << endl;

    return 0;
}
