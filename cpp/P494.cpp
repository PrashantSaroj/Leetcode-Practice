#include <bits/stdc++.h>
using namespace std;

typedef pair<vector<int>, int> tc_type;

class Solution {
    map<pair<int, int>, int> memo;

    int targetRecur(vector<int>& nums, int start, int target) {
        if (start == nums.size())
            return target == 0;

        pair<int, int> curKey = {start, target};
        if (memo.find(curKey) != memo.end())
            return memo[curKey];

        memo[curKey] = targetRecur(nums, start + 1, target - nums[start]) + targetRecur(nums, start + 1, target + nums[start]);
        return memo[curKey];
    }

   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return targetRecur(nums, 0, target);
    }
};

int main() {
    vector<tc_type> testCases = {
        {{1, 1, 1, 1, 1}, 3},
        {{1}, 1},
    };

    for (auto& t : testCases)
        cout << Solution().findTargetSumWays(t.first, t.second) << endl;
    return 0;
}
