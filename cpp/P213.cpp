#include <bits/stdc++.h>
using namespace std;

class Solution {
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int profit[n];
        profit[n - 1] = nums[n - 1];
        profit[n - 2] = max(nums[n - 2], nums[n - 1]);
        for (int i = n - 3; i >= 0; i--) {
            profit[i] = max(nums[i] + profit[i + 2], profit[i + 1]);
        }
        return max(profit[0], profit[1]);
    }

   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> nums0(nums.begin() + 1, nums.end());
        vector<int> numsL(nums.begin(), nums.end() - 1);
        return max(robLinear(nums0), robLinear(numsL));
    }
};

int main() {
    vector<vector<int>> testCases = {
        {2, 3, 2},
        {1, 2, 3, 1},
        {1, 2, 3},
    };
    for (auto& t : testCases) {
        cout << Solution().rob(t) << endl;
    }
}
