#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getBitCount(int n) {
        int count = 0;
        while (n) {
            if (n & 1) {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }

    bool isSorted(vector<int>& nums) {
        for (int i = 1, N = nums.size(); i < N; i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }

   public:
    bool canSortArray(vector<int>& nums) {
        int groupStart = 0, curBits = getBitCount(nums[0]);
        for (int i = 1, N = nums.size(); i < N; i++) {
            int newBits = getBitCount(nums[i]);
            if (newBits != curBits) {
                sort(nums.begin() + groupStart, nums.begin() + i);
                // update counters
                groupStart = i;
                curBits = newBits;
            }
        }
        sort(nums.begin() + groupStart, nums.end());

        return isSorted(nums);
    }
};

int main() {
    vector<vector<int>> testCases = {
        {8, 4, 2, 30, 15},
        {1, 2, 3, 4, 5},
        {3, 16, 8, 4, 2},
    };

    for (auto& t : testCases)
        cout << Solution().canSortArray(t) << endl;

    return 0;
}
