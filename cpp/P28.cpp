#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> tc;

class Solution {
    bool existsAtIndex(string &haystack, string &needle, int index) {
        for (int i = 0; i < needle.size(); i++) {
            if (needle[i] != haystack[i + index]) {
                return false;
            }
        }
        return true;
    }

   public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i <= n - m; i++) {
            if (existsAtIndex(haystack, needle, i)) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<tc> testCases = {
        {"sadbutsad", "sad"},
        {"leetcode", "leeto"},
        {"a", "a"}};

    Solution sol;

    for (tc &t : testCases) {
        cout << sol.strStr(t.first, t.second) << endl;
    }
    return 0;
}
