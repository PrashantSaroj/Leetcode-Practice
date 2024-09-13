#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
   public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int N = arr.size();
        vector<int> cumXor(N);

        cumXor[0] = arr[0];
        for (int i = 1; i < N; i++) {
            cumXor[i] = arr[i] ^ cumXor[i - 1];
        }

        int M = queries.size();
        vector<int> queryResult(M);
        for (int i = 0; i < M; i++) {
            int l = queries[i][0], r = queries[i][1];
            if (l) {
                queryResult[i] = cumXor[l - 1] ^ cumXor[r];
            } else {
                // l == 0 case
                queryResult[i] = cumXor[r];
            }
        }
        return queryResult;
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 8};
    vector<vector<int>> queries = {
        {0, 1}, {1, 2}, {0, 3}, {3, 3}};

    vector<int> results = Solution().xorQueries(nums, queries);
    printVector(results);

    return 0;
}
