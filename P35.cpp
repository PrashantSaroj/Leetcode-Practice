#include <bits/stdc++.h>
using namespace std;

typedef pair<vector<int>, int> tcType;

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // now l == r
        if (target < nums[l]) {
            return l;
        } else {
            return r + 1;
        }
    }
};

int main() {
    vector<tcType> testCases = {
        {{1, 3, 5, 6}, 5},
        {{1, 3, 5, 6}, 2},
        {{1, 3, 5, 6}, 7},
        {{1, 3, 5, 6}, 0}};
    Solution sol;

    for (auto& t : testCases) {
        cout << sol.searchInsert(t.first, t.second) << endl;
    }
    return 0;
}
