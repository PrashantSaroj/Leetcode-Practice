#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool areAlmostEqual(string s1, string s2) {
        int N = s1.size();
        vector<int> diff;
        for (int i = 0; i < N; i++)
            if (s1[i] != s2[i]) diff.push_back(i);

        if (diff.size() == 0) {
            return true;
        }
        if (diff.size() == 2) {
            return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
        }
        return false;
    }
};

int main() {
    vector<pair<string, string>> testCases = {
        {"caa", "aaz"},
        {"bank", "kanb"},
        {"attack", "defend"},
        {"kelb", "kelb"},
    };

    for (auto &t : testCases)
        cout << Solution().areAlmostEqual(t.first, t.second) << endl;
    return 0;
}
