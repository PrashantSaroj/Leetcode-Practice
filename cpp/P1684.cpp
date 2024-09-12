#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool allowedChars[26];
        for (char c : allowed) {
            allowedChars[c - 'a'] = true;
        }

        int consistentCount = 0;
        for (string word : words) {
            bool isConsistent = true;
            for (char c : word) {
                if (!allowedChars[c - 'a']) {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent) {
                consistentCount++;
            }
        }
        return consistentCount;
    }
};

int main() {
    int T = 3;
    vector<string> allowedVec = {"ab", "abc", "cad"};
    vector<vector<string>> wordsVec = {
        {"ad", "bd", "aaab", "baa", "badab"},
        {"a", "b", "c", "ab", "ac", "bc", "abc"},
        {"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"}};
    Solution sol;

    while (T--) {
        cout << sol.countConsistentStrings(allowedVec[T], wordsVec[T]) << endl;
    }

    return 0;
}
