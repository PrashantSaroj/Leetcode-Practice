#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int N = original.size();
        if (m * n != N) {
            return vector<vector<int>>{};
        }
        vector<vector<int>> array2D(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                array2D[i][j] = original[i * n + j];
            }
        }
        return array2D;
    }
};
