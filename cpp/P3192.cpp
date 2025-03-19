#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& nums) {
        int flips = 0;
        for (int i = 0; i < nums.size(); i++)
            if (!((flips & 1) xor nums[i])) flips++;
        return flips;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {0, 1, 1, 0, 1},
        {1, 0, 0, 0},
    };
    for (auto& t : testCases)
        cout << Solution().minOperations(t) << endl;
}
