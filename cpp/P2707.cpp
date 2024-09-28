#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
   public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
        int n = s.size();

        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + 1;

            for (int length = 1; length < n - i + 1; length++) {
                string currWord = s.substr(i, length);
                if (dictSet.count(currWord)) {
                    dp[i] = min(dp[i], dp[i + length]);
                }
            }
        }
        return dp[0];
    }
};

int main() {
    string s = "leetscode";
    vector<string> dictionary = {"leet", "code", "leetcode"};
    cout << Solution().minExtraChar(s, dictionary) << endl;

    return 0;
}
