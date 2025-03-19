#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestNiceSubarray(vector<int>& nums) {
        int windowStart = 0, maxLength = 1;
        int usedBits = nums[0];
        for (int windowEnd = 1; windowEnd < nums.size(); windowEnd++) {
            while ((usedBits & nums[windowEnd]) != 0) usedBits ^= nums[windowStart++];
            usedBits |= nums[windowEnd];
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 3, 8, 48, 10},
        {3, 1, 5, 11, 13},
    };

    for (auto& t : testCases)
        cout << Solution().longestNiceSubarray(t) << endl;
}
