#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        pair<int, int> indexMap[M * N];
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                indexMap[mat[i][j]] = {i, j};

        vector<int> rowFreq(M, 0), colFreq(N, 0);
        for (int i = 0; i < M * N; i++) {
            auto [currI, currJ] = indexMap[arr[i]];
            rowFreq[currI] += 1;
            colFreq[currJ] += 1;
            if (rowFreq[currI] == N || colFreq[currJ] == M) return i;
        }
        return 0;
    }
};

int main() {
    vector<pair<vector<int>, vector<vector<int>>>> testCases = {
        {{1, 3, 4, 2}, {{1, 4}, {2, 3}}},
        {{2, 8, 7, 4, 1, 3, 5, 6, 9}, {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}}},
    };

    for (auto& t : testCases)
        cout << Solution().firstCompleteIndex(t.first, t.second) << endl;

    return 0;
}
