#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& nums) {
        int flips = 0, N = nums.size();
        for (int winStart = 0; winStart <= N - 3; winStart++) {
            if (!nums[winStart]) {
                nums[winStart] = !nums[winStart];
                nums[winStart + 1] = !nums[winStart + 1];
                nums[winStart + 2] = !nums[winStart + 2];
                flips++;
            }
        }
        return nums[N - 1] && nums[N - 2] ? flips : -1;
    }
};

int main() {
    vector<vector<int>> testCases = {{0, 1, 1, 1, 0, 0}};
    for (auto& t : testCases)
        cout << Solution().minOperations(t) << endl;
}
