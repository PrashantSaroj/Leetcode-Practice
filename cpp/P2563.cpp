#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long fairPairs = 0;
        for (int i = 0; i < n - 1; i++) {
            int loInd = lower_bound(nums.begin(), nums.end(), lower - nums[i]) - nums.begin();
            int upInd = upper_bound(nums.begin(), nums.end(), upper - nums[i]) - nums.begin();
            loInd = max(loInd, i + 1);
            fairPairs += max(0, upInd - loInd);
        }
        return fairPairs;
    }
};

typedef tuple<vector<int>, int, int> tc_type;

int main() {
    vector<tc_type> testCases = {
        {{0, 1, 7, 4, 4, 5}, 3, 6},
        {{1, 7, 9, 2, 5}, 11, 11},
    };
    for (auto& t : testCases) {
        printf("Fair pairs: %lld\n", Solution().countFairPairs(get<0>(t), get<1>(t), get<2>(t)));
    }
}
