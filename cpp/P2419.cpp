#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestSubarray(vector<int>& nums) {
        int maxAnd = *max_element(nums.begin(), nums.end());
        int maxLen = 0, i = 0, N = nums.size();
        while (i < N) {
            if (nums[i] == maxAnd) {
                int currLen = 0;
                while (i < N && nums[i] == maxAnd) {
                    currLen++;
                    i++;
                }
                maxLen = max(maxLen, currLen);
            } else {
                i++;
            }
        }
        return maxLen;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3, 3, 2, 2},
        {1, 2, 3, 4}};
    Solution sol;

    for (auto& tc : testCases) {
        cout << sol.longestSubarray(tc) << endl;
    }

    return 0;
}
