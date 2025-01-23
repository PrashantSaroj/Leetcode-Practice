#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countServers(vector<vector<int>>& grid) {
        int count = 0, M = grid.size(), N = grid[0].size();
        vector<int> rowFreq(M, 0), colFreq(N, 0);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j]) {
                    rowFreq[i]++;
                    colFreq[j]++;
                }
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] && (rowFreq[i] > 1 || colFreq[j] > 1)) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{1, 0}, {0, 1}},
        {{1, 0}, {1, 1}},
        {{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}},
    };

    for (auto& t : testCases)
        cout << Solution().countServers(t) << endl;
    return 0;
}
