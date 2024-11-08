#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
   public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int N = nums.size(), curXor = 0;
        vector<int> queryResults(N, 0);
        int maxOnes = (1 << maximumBit) - 1;

        for (int i = 0; i < N; i++) {
            curXor = curXor ^ nums[i];
            queryResults[N - i - 1] = (curXor & maxOnes) ^ maxOnes;
        }
        return queryResults;
    }
};

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{0, 1, 1, 3}, 2},
        {{2, 3, 4, 7}, 3},
        {{0, 1, 2, 2, 5, 7}, 3},
    };

    for (auto& t : testCases)
        printVector(Solution().getMaximumXor(t.first, t.second));

    return 0;
}
