#include <bits/stdc++.h>
using namespace std;

class Solution {
    int lower_bound(vector<int>& nums, int target) {
        int N = nums.size();
        int lb = -1;

        int l = 0, r = N - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
                if (nums[mid] == target) {
                    lb = mid;
                }
            } else {
                l = mid + 1;
            }
        }
        return lb;
    }

    int upper_bound(vector<int>& nums, int target) {
        int N = nums.size();
        int ub = -1;

        int l = 0, r = N - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
                if (nums[mid] == target) {
                    ub = mid;
                }
            } else {
                r = mid - 1;
            }
        }
        return ub;
    }

   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums, target);
        int r = upper_bound(nums, target);
        return vector<int>{l, r};
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> posi = Solution().searchRange(nums, 7);
    cout << posi[0] << " " << posi[1] << endl;

    return 0;
}
