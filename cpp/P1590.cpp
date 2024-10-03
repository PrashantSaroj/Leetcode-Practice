#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minSubarray(vector<int>& nums, int p) {
        long totalSum = accumulate(nums.begin(), nums.end(), (long)0);
        int rem = totalSum % p;
        if (rem == 0) {
            return 0;
        }

        unordered_map<int, int> prefix;
        prefix[0] = -1;
        int minLength = -1;
        long curRem = 0, reqRem;
        for (int i = 0, n = nums.size(); i < n; i++) {
            curRem = (curRem + nums[i]) % p;
            reqRem = ((curRem - rem) % p + p) % p;
            if (prefix.find(reqRem) != prefix.end()) {
                int curLen = (i - prefix[reqRem]);
                if (minLength < 0 || curLen < minLength) {
                    minLength = curLen;
                }
            }
            prefix[curRem] = i;
        }

        return minLength == nums.size() ? -1 : minLength;
    }
};

int main() {
    vector<vector<int>> t1 = {
        {17, 6, 22, 31, 25, 4, 18, 32, 18, 26, 2, 31, 26, 8, 12, 2},
        {3, 1, 4, 2},
        {6, 3, 5, 2},
        {1, 2, 3}};
    vector<int> t2 = {142, 6, 9, 3};

    for (int i = 0; i < t1.size(); i++) {
        cout << Solution().minSubarray(t1[i], t2[i]) << endl;
        break;
    }

    return 0;
}
