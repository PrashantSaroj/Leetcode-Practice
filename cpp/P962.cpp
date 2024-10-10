#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> valStack = {nums[0]}, indStack = {0};
        int rampWidth = 0;
        for (int i = 1, n = nums.size(); i < n; i++) {
            auto lb = lower_bound(valStack.begin(), valStack.end(), nums[i], greater<int>());
            if (lb != valStack.end()) {
                rampWidth = max(rampWidth, i - indStack[lb - valStack.begin()]);
            }

            if (valStack.back() > nums[i]) {
                valStack.push_back(nums[i]);
                indStack.push_back(i);
            }
        }
        return rampWidth;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {6, 0, 8, 2, 1, 5},
        {9, 8, 1, 0, 1, 9, 4, 0, 4, 1},
    };
    for (auto& tc : testCases) {
        cout << Solution().maxWidthRamp(tc) << endl;
    }
    return 0;
}