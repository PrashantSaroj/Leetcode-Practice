#include <bits/stdc++.h>
using namespace std;

typedef pair<int, vector<int>> testCase;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> targetSumPairs;

        for (int i = 0; i + 3 < nums.size(); i++) {
            for (int j = i + 2; j + 1 < nums.size(); j++) {
                int l = i + 1, r = nums.size() - 1;
                while (l < j && r > j) {
                    long currSum = (long)nums[i] + (long)nums[j] + (long)nums[l] + (long)nums[r];
                    if (currSum == target) {
                        targetSumPairs.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    } else if (currSum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }

        return vector<vector<int>>(targetSumPairs.begin(), targetSumPairs.end());
    }
};

int main() {
    vector<testCase> TC = {
        {0, {1}},
        {0, {1, 0, -1, 0, -2, 2}},
        {8, {2, 2, 2, 2, 2}}};

    Solution sol;

    for (testCase &t : TC) {
        vector<vector<int>> sumPairs = sol.fourSum(t.second, t.first);
        for (vector<int> &ans : sumPairs) {
            cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
        }
        cout << "-------END-------\n"
             << endl;
    }
}
