#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"

using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ringSize = n - 1;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < i + ringSize; j++) {
                // (i, j), (j, i+ringSize), (i+ringSize, 2i+ringSize-j), (2i+ringSize-j, i)
                int t1 = matrix[i][j];
                int t2 = matrix[j][i + ringSize];
                int t3 = matrix[i + ringSize][2 * i + ringSize - j];
                int t4 = matrix[2 * i + ringSize - j][i];

                matrix[i][j] = t4;
                matrix[j][i + ringSize] = t1;
                matrix[i + ringSize][2 * i + ringSize - j] = t2;
                matrix[2 * i + ringSize - j][i] = t3;
            }
            ringSize -= 2;
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}};
    Solution sol;
    sol.rotate(matrix);

    printVecOfVector(matrix);
    return 0;
}
