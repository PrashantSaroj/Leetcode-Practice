#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxAscendingSum(vector<int>& nums) {
        int N = nums.size();
        int cur = 0, maxSum = 0, curSum = nums[0];
        while (++cur < N) {
            if (nums[cur - 1] >= nums[cur]) {
                maxSum = max(maxSum, curSum);
                curSum = nums[cur];
            } else {
                curSum += nums[cur];
            }
        }
        maxSum = max(maxSum, curSum);
        return maxSum;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {10, 20, 30, 5, 10, 50},
        {10, 20, 30, 40, 50},
        {12, 17, 15, 13, 10, 11, 12},
    };

    for (auto& t : testCases) {
        cout << Solution().maxAscendingSum(t) << endl;
    }

    return 0;
}
