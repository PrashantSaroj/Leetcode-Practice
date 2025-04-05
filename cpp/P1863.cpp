#include <bits/stdc++.h>
using namespace std;

class Solution {
    int subsetXor(vector<int>& nums, int subset) {
        int res = 0;
        for (int i = 0, N = nums.size(); i < N; i++) {
            res ^= (subset >> i) & 1 ? nums[i] : 0;
        }
        return res;
    }

   public:
    int subsetXORSum(vector<int>& nums) {
        int xorSum = 0;
        for (int i = 0, subsetCount = 1 << nums.size(); i < subsetCount; i++) {
            xorSum += subsetXor(nums, i);
        }
        return xorSum;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 3},
        {5, 1, 6},
        {3, 4, 5, 6, 7, 8},
    };
    for (auto& t : testCases) cout << Solution().subsetXORSum(t) << endl;
}
