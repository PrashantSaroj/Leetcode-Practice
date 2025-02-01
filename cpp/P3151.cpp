#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1, N = nums.size(); i < N; i++)
            if (!((nums[i - 1] & 1) ^ (nums[i] & 1))) return false;
        return true;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1},
        {2, 1, 4},
        {4, 3, 1, 6},
    };

    for (auto& t : testCases)
        cout << Solution().isArraySpecial(t) << endl;
    return 0;
}
