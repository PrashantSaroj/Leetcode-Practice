#include <bits/stdc++.h>
using namespace std;

#define point pair<int, int>

class Solution {
    vector<point> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool insideGrid(int i, int j, int m, int n) {
        return i >= 0 and i < m and j >= 0 and j < n;
    }

    bool findIsland(vector<vector<int>>& grid, vector<vector<int>>& superGrid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        queue<point> bfsQ;
        bfsQ.push(pair(i, j));

        vector<point> island;

        while (!bfsQ.empty()) {
            point curr = bfsQ.front();
            bfsQ.pop();

            if (grid[curr.first][curr.second] != 1) {
                continue;
            }

            for (point d : dir) {
                point neighbor = pair(curr.first + d.first, curr.second + d.second);
                if (insideGrid(neighbor.first, neighbor.second, m, n)) {
                    bfsQ.push(neighbor);
                }
            }

            // mark it as island found;
            grid[curr.first][curr.second] = 2;
            island.push_back(curr);
        }

        for (point p : island) {
            if (!superGrid[p.first][p.second]) {
                return false;
            }
        }
        return true;
    }

   public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size(), n = grid2[0].size();
        int islandCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                point curr = pair(i, j);
                if (grid2[i][j] == 1 and findIsland(grid2, grid1, i, j)) {
                    islandCount++;
                }
            }
        }

        return islandCount;
    }
};

int main() {
    vector<vector<int>> grid1 =
        {{1, 1, 1, 1, 0, 0}, {1, 1, 0, 1, 0, 0}, {1, 0, 0, 1, 1, 1}, {1, 1, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 1, 1}, {1, 0, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 0}};
    vector<vector<int>> grid2 =
        {{1, 1, 1, 1, 0, 1}, {0, 0, 1, 0, 1, 0}, {1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 0}, {0, 1, 1, 1, 1, 1}, {1, 1, 0, 1, 1, 1}, {1, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0}};

    Solution sol;
    cout << sol.countSubIslands(grid1, grid2) << endl;

    return 0;
}
