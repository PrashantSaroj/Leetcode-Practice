#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        set<vector<int>> zeroSumTriplets;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int currSum = nums[i] + nums[l] + nums[r];
                if (currSum == 0) {
                    zeroSumTriplets.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                } else if (currSum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return vector<vector<int>>(zeroSumTriplets.begin(), zeroSumTriplets.end());
    }
};

int main() {
    vector<vector<int>> testCases = {
        {-1, 0, 1, 2, -1, -4},
        {0, 1, 1},
        {0, 0, 0}};

    Solution sol;

    for (auto &tc : testCases) {
        vector<vector<int>> triplets = sol.threeSum(tc);
        for (auto &tuple : triplets) {
            cout << "[" << tuple[0] << ", " << tuple[1] << ", " << tuple[2] << "], ";
        }
        cout << endl;
    }

    return 0;
}