#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int curr = 0, N = nums.size();
        for (int i = 0; i < N; i++) {
            if (nums[i] != val) {
                nums[curr] = nums[i];
                curr++;
            }
        }
        return curr;
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    cout << Solution().removeElement(nums, val) << endl;
    printVector(nums);
    return 0;
}
