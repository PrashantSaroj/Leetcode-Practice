#include <bits/stdc++.h>
using namespace std;

class Solution {
    int M, N;
    const vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    inline bool isValid(int r, int c) {
        return r >= 0 && r < M && c >= 0 && c < N;
    }

    vector<pair<int, int>> getNeighbors(int r, int c) {
        vector<pair<int, int>> neighbors;
        for (auto& d : dirs) {
            pair<int, int> cur = {r + d.first, c + d.second};
            if (isValid(cur.first, cur.second)) {
                neighbors.push_back(cur);
            }
        }
        return neighbors;
    }

    int catchAll(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        int fishCount = grid[r][c];
        visited[r][c] = true;
        queue<pair<int, int>> bfsQ({{r, c}});

        while (!bfsQ.empty()) {
            auto& [curX, curY] = bfsQ.front();

            auto neighbors = getNeighbors(curX, curY);
            for (auto& [neighX, neighY] : neighbors) {
                if (grid[neighX][neighY] && !visited[neighX][neighY]) {
                    visited[neighX][neighY] = true;
                    fishCount += grid[neighX][neighY];
                    bfsQ.push({neighX, neighY});
                }
            }
            bfsQ.pop();
        }
        return fishCount;
    }

   public:
    int findMaxFish(vector<vector<int>>& grid) {
        M = grid.size(), N = grid[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        int maxFish = 0;

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (grid[i][j] && !visited[i][j]) {
                    maxFish = max(maxFish, catchAll(grid, visited, i, j));
                }
        return maxFish;
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}, {0, 3, 2, 0}},
        {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}},
        {{8, 6}, {2, 6}},
    };

    for (auto& t : testCases)
        cout << Solution().findMaxFish(t) << endl;
    return 0;
}
