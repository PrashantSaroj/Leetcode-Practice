#include <bits/stdc++.h>

#include "utils/KMP.cpp"
using namespace std;

class Solution {
   public:
    string shortestPalindrome(string s) {
        string smecher = s + "#" + string(s.rbegin(), s.rend());

        vector<int> pi = prefixFunction(smecher);
        int longestPallindrome = pi.back();

        smecher = string(s.begin() + longestPallindrome, s.end());
        reverse(smecher.begin(), smecher.end());
        return smecher + s;
    }
};

int main() {
    vector<string> testCases = {"aacecaaa", "abcd", ""};
    for (auto &t : testCases) {
        cout << Solution().shortestPalindrome(t) << endl;
    }
    return 0;
}
