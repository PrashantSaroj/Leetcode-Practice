#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long maximumTripletValue(vector<int>& nums) {
        long long curMax = nums[0], maxDif = nums[0] - nums[1], maxVal = 0;
        for (int k = 2, N = nums.size(); k < N; k++) {
            maxVal = max(maxVal, maxDif * nums[k]);
            curMax = max(curMax, (long long)nums[k - 1]);
            maxDif = max(maxDif, curMax - nums[k]);
        }
        return maxVal;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {12, 6, 1, 2, 7},
        {1, 10, 3, 4, 19},
        {1, 2, 3},
    };
    for (auto& t : testCases) cout << Solution().maximumTripletValue(t) << endl;
}
