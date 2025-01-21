#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long gridGame(vector<vector<int>>& grid) {
        int N = grid[0].size();
        vector<vector<long long>> cumSum(2, vector<long long>(N + 2, 0));
        for (int i = 1; i <= N; i++) {
            cumSum[0][i] = cumSum[0][i - 1] + grid[0][i - 1];
            cumSum[1][i] = cumSum[1][i - 1] + grid[1][i - 1];
        }

        long long optScore = INT_MAX;
        for (int i = 0; i < N; i++) {
            long long path1Score = cumSum[0][N] - cumSum[0][i + 1];
            long long path2Score = cumSum[1][i];
            optScore = min(optScore, max(path1Score, path2Score));
        }
        return optScore;
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{2, 5, 4}, {1, 5, 1}},
        {{3, 3, 1}, {8, 5, 2}},
        {{1, 3, 1, 15}, {1, 3, 3, 1}},
    };

    for (auto& t : testCases)
        cout << Solution().gridGame(t) << endl;

    return 0;
}
