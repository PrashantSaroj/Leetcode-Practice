#include <bits/stdc++.h>
using namespace std;

bool increasingCheck(int prev, int cur) {
    return cur > prev;
}

bool decreasingCheck(int prev, int cur) {
    return cur < prev;
}

class Solution {
    int longestSubarray(vector<int>& nums, bool (*condition)(int, int)) {
        int prev = 0, cur = 0, N = nums.size(), longest = 0;
        while (++cur < N) {
            if (!condition(nums[cur - 1], nums[cur])) {
                longest = max(longest, cur - prev);
                prev = cur;
            }
        }
        longest = max(longest, cur - prev);
        return longest;
    }

   public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longestIncreasing = longestSubarray(nums, &increasingCheck);
        int longestDecreasing = longestSubarray(nums, &decreasingCheck);
        return max(longestIncreasing, longestDecreasing);
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 4, 3, 3, 2},
        {3, 3, 3, 3},
        {3, 2, 1},
    };

    for (auto& t : testCases) {
        cout << Solution().longestMonotonicSubarray(t) << endl;
    }
    return 0;
}
