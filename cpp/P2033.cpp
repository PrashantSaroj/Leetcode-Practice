#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool convergesToUniVal(vector<int>& flattened, int x) {
        int rem = flattened[0] % x;
        for (int n : flattened) {
            if (n % x != rem) return false;
        }
        return true;
    }

   public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flattened;
        for (auto& row : grid) {
            for (auto val : row) {
                flattened.push_back(val);
            }
        }
        // check if possible convergence
        if (!convergesToUniVal(flattened, x)) return -1;

        sort(flattened.begin(), flattened.end());

        // calc prefix & suffix sum;
        int N = flattened.size();
        vector<int> prefixSum(N, 0), suffixSum(N, 0);
        for (int i = 1; i < N; i++) {
            prefixSum[i] = prefixSum[i - 1] + flattened[i - 1];
            suffixSum[N - i - 1] = suffixSum[N - i] + flattened[N - i];
        }

        // consider each element as potential uni-value
        int minOps = INT_MAX;
        for (int i = 0; i < N; i++) {
            int leftOps = (i * flattened[i] - prefixSum[i]) / x;
            int riteOps = (suffixSum[i] - (N - i - 1) * flattened[i]) / x;
            minOps = min(minOps, leftOps + riteOps);
        }
        return minOps;
    }
};

int main() {
    vector<pair<vector<vector<int>>, int>> testCases = {
        {{{2, 4}, {6, 8}}, 2},
        {{{1, 5}, {2, 3}}, 1},
        {{{1, 2}, {3, 4}}, 2},
    };
    for (auto& t : testCases) {
        cout << Solution().minOperations(t.first, t.second) << endl;
    }
}
