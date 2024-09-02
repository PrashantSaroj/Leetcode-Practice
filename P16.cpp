#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = INF;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int currDiff = nums[i] + nums[l] + nums[r] - target;

                // make current diff as close to zero as possible
                if (currDiff == 0) {
                    return target;
                } else if (currDiff < 0) {
                    l++;
                } else {
                    r--;
                }

                if (abs(currDiff) < abs(minDiff)) {
                    minDiff = currDiff;
                }
            }
        }
        return target + minDiff;
    }
};

int main() {
    vector<vector<int>> testCases = {{-1, 2, 1, -4}, {0, 0, 0}};
    Solution sol;

    for (int i = 0; i < testCases.size(); i++) {
        cout << sol.threeSumClosest(testCases[i], 1) << endl;
    }

    return 0;
}
