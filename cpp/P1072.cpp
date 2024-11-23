#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> flipBits(vector<vector<int>>& matrix, int colCount, int i) {
        vector<int> flipped(colCount);
        for (int j = 0; j < colCount; j++) {
            flipped[j] = !matrix[i][j];
        }
        return flipped;
    }

   public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<vector<int>, int> patFreq;
        int colCount = matrix[0].size(), rowCount = matrix.size();
        for (int i = 0; i < rowCount; i++) {
            if (matrix[i][0]) {
                patFreq[matrix[i]] += 1;
            } else {
                patFreq[flipBits(matrix, colCount, i)] += 1;
            }
        }
        int maxEqualRows = 0;
        for (auto& t : patFreq)
            maxEqualRows = max(maxEqualRows, t.second);

        return maxEqualRows;
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{0, 1}, {1, 1}},
        {{0, 1}, {1, 0}},
        {{0, 0, 0}, {0, 0, 1}, {1, 1, 0}},
    };

    for (auto& t : testCases) {
        cout << Solution().maxEqualRowsAfterFlips(t) << endl;
    }

    return 0;
}
