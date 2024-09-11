#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

#define INF 0x3f3f3f3f

class Solution {
    bool isSortedReverse(vector<int>& nums) {
        int N = nums.size();
        for (int i = 1; i < N; i++) {
            if (nums[i] > nums[i - 1]) {
                return false;
            }
        }
        return true;
    }

   public:
    void nextPermutation(vector<int>& nums) {
        if (isSortedReverse(nums)) {
            sort(nums.begin(), nums.end());
            return;
        }

        int N = nums.size();
        for (int j = N - 2; j >= 0; j--) {
            int swapCandidate = -1, closestGreater = INF;
            for (int i = j + 1; i < N; i++) {
                if (nums[i] > nums[j] && nums[i] < closestGreater) {
                    closestGreater = nums[i];
                    swapCandidate = i;
                }
            }

            if (swapCandidate != -1) {
                int tmp = nums[swapCandidate];
                nums[swapCandidate] = nums[j];
                nums[j] = tmp;
                sort(nums.begin() + j + 1, nums.end());
                return;
            }
        }
    }
};

int main() {
    vector<int> nums = {4, 2, 0, 2, 3, 2, 0};
    Solution sol;

    for (int i = 0; i < 6; i++) {
        sol.nextPermutation(nums);
        printVector(nums);
    }

    return 0;
}
