#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

typedef pair<int, int> coordinate;

class Solution {
    vector<coordinate> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<coordinate> findWater(vector<vector<int>>& isWater, int M, int N) {
        vector<coordinate> water;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (isWater[i][j]) water.push_back({i, j});
        return water;
    }

    inline bool isInside(int i, int j, int M, int N) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }

    vector<coordinate> getNeighbors(coordinate p, int M, int N) {
        vector<coordinate> neighbor;
        for (auto& d : dirs) {
            coordinate cur = {p.first + d.first, p.second + d.second};
            if (isInside(cur.first, cur.second, M, N)) neighbor.push_back(cur);
        }
        return neighbor;
    }

   public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int M = isWater.size(), N = isWater[0].size();
        vector<vector<int>> heights(M, vector<int>(N, -1));

        vector<coordinate> water = findWater(isWater, M, N);
        queue<pair<coordinate, int>> bfsQ;
        for (auto& c : water) {
            heights[c.first][c.second] = 0;
            bfsQ.push({c, 0});
        }

        while (!bfsQ.empty()) {
            auto& [curCoordinate, h] = bfsQ.front();
            auto neighbors = getNeighbors(curCoordinate, M, N);
            for (auto n : neighbors) {
                if (heights[n.first][n.second] == -1) {
                    heights[n.first][n.second] = h + 1;
                    bfsQ.push({n, h + 1});
                }
            }

            bfsQ.pop();
        }
        return heights;
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{0, 1}, {0, 0}},
        {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}},
    };

    for (auto& t : testCases)
        printVecOfVector(Solution().highestPeak(t));

    return 0;
}
