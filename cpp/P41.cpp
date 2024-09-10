#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            int curr = nums[i];
            while (curr >= 1 && curr <= N && nums[curr - 1] != curr) {
                // put i into index i-1
                int tmp = nums[curr - 1];
                nums[curr - 1] = curr;
                curr = tmp;
            }
        }

        for (int i = 0; i < N; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return N + 1;
    }
};

int main() {
    vector<int> nums = {3, 4, 5, 1, 2, 6};
    cout << Solution().firstMissingPositive(nums) << endl;

    return 0;
}
