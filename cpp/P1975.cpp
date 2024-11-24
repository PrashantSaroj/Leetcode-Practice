#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negCount = 0, absMin = 100001;
        long long totalAbsSum = 0;
        for (int i = 0, rowCount = matrix.size(), colCount = matrix[0].size(); i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                if (matrix[i][j] < 0) negCount++;
                absMin = min(absMin, abs(matrix[i][j]));
                totalAbsSum += abs(matrix[i][j]);
            }
        }
        return negCount & 1 ? totalAbsSum - 2 * absMin : totalAbsSum;
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{1, -1}, {-1, 1}},
        {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}},
    };

    for (auto& t : testCases)
        cout << Solution().maxMatrixSum(t) << endl;

    return 0;
}
