#include <bits/stdc++.h>
using namespace std;

const int CONST_MOD = 1000000007;

class Solution {
   public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int dp[high + 1] = {};
        dp[0] = 1;
        for (int i = 1; i <= high; i++) {
            if (i - zero >= 0) dp[i] = dp[i - zero];
            if (i - one >= 0) dp[i] = (dp[i] + dp[i - one]) % CONST_MOD;
        }

        int goodStrings = 0;
        for (int i = low; i <= high; i++)
            goodStrings = (goodStrings + dp[i]) % CONST_MOD;
        return goodStrings;
    }
};

int main() {
    cout << Solution().countGoodStrings(3, 3, 1, 1) << endl;
    cout << Solution().countGoodStrings(2, 3, 1, 2) << endl;

    return 0;
}
