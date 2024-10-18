#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0, numsLen = nums.size();
        for (int n : nums) maxOR = maxOR | n;

        int subsetCount = 0;
        for (int i = 1, N = pow(2, numsLen); i < N; i++) {
            int curOR = 0;
            for (int j = 0; j < numsLen; j++) {
                // if jth bit is set in i, then this element is included
                if (i & (1 << j)) curOR = curOR | nums[j];
            }
            if (maxOR == curOR) subsetCount++;
        }
        return subsetCount;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {3, 1},
        {2, 2, 2},
        {3, 2, 1, 5},
    };
    for (auto& t : testCases)
        cout << Solution().countMaxOrSubsets(t) << endl;

    return 0;
}
