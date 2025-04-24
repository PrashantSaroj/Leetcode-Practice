#include <bits/stdc++.h>
using namespace std;

class Solution {
    int countDistinctElements(vector<int>& nums) {
        unordered_set<int> numsSet;
        for (int n : nums) numsSet.insert(n);
        return numsSet.size();
    }

   public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> curWindow;
        int r = 0, N = nums.size(), ans = 0;
        int d = countDistinctElements(nums);
        for (int l = 0; l < N; l++) {
            while (r < N && curWindow.size() < d) {
                curWindow[nums[r++]]++;
            }
            // r is not in the window
            if (curWindow.size() == d) ans += (N - r + 1);

            curWindow[nums[l]]--;
            if (!curWindow[nums[l]]) curWindow.erase(nums[l]);
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 3, 1, 2, 2}};
    for (auto& t : testCases) {
        printf("#Complete sub-arrays: %i\n", Solution().countCompleteSubarrays(t));
    }
}
