#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> longestIncreasingSubSequence(vector<int>& nums, int N) {
        vector<int> dp(N, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i]++;
        }
        return dp;
    }

    vector<int> longestDecreasingSubSequence(vector<int>& nums, int N) {
        vector<int> dp(N, 0);
        for (int i = N - 1; i >= 0; i--) {
            for (int j = i + 1; j < N; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i]++;
        }
        return dp;
    }

   public:
    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size();
        vector<int> lcs = longestIncreasingSubSequence(nums, N);
        vector<int> dcs = longestDecreasingSubSequence(nums, N);
        int maxMountainArray = 0;
        for (int i = 0; i < N; i++) {
            if (lcs[i] > 1 && dcs[i] > 1) {
                maxMountainArray = max(maxMountainArray, lcs[i] + dcs[i] - 1);
            }
        }
        return N - maxMountainArray;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {9, 8, 1, 7, 6, 5, 4, 3, 2, 1},
        {1, 3, 1},
        {2, 1, 1, 5, 6, 2, 3, 1},
    };

    for (auto& t : testCases)
        cout << Solution().minimumMountainRemovals(t) << endl;

    return 0;
}
