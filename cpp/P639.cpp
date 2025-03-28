#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution {
    int N;
    string s;
    vector<int> nWays;

    int waysHelper(int i) {
        if (i == N) return 1;
        if (nWays[i] != -1) return nWays[i];
        // solve both subproblems
        long curAns = 0;
        if (s[i] != '0') {
            int multiplier = s[i] == '*' ? 9 : 1;
            curAns += multiplier * waysHelper(i + 1);
            curAns %= MOD;
        }

        if (i < N - 1) {
            int multiplier = 0;
            if (s[i] == '*' && s[i + 1] == '*')
                multiplier = 17;  // '*' followed by '*' can form 17 possibilities (from 10-19, 20-26)
            else if (s[i] == '1' && s[i + 1] == '*')
                multiplier = 9;  // '1*' can form 9 possibilities (10 to 19)
            else if (s[i] == '2' && s[i + 1] == '*')
                multiplier = 6;  // '2*' can form 6 possibilities (20 to 26)
            else if (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))
                multiplier = 1;

            if (multiplier) {                              // Correct this check
                curAns += multiplier * waysHelper(i + 2);  // Proceed to the next valid index
                curAns %= MOD;
            }
        }
        nWays[i] = curAns;
        return nWays[i];
    }

   public:
    int numDecodings(string& s) {
        N = s.size();
        this->s = s;
        nWays.resize(N, -1);
        // call recursive helper
        return waysHelper(0);
    }
};

int main() {
    string s = "**";
    cout << Solution().numDecodings(s) << endl;
}
