#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool possibleCapability(vector<int>& nums, int k, int cap) {
        int i = 0;
        while (k > 0 && i < nums.size()) {
            if (nums[i] <= cap) {
                k--;
                i++;
            }
            i++;
        }
        return !k;
    }

   public:
    int minCapability(vector<int>& nums, int k) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int ans = r;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (possibleCapability(nums, k, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{2, 3, 5, 9}, 2},
        {{2, 7, 9, 3, 1}, 2},
    };

    for (auto& t : testCases)
        cout << Solution().minCapability(t.first, t.second) << endl;
}
