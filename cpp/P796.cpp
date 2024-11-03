#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool rotateString(string s, string goal) {
        string target = s + s;
        return target.find(goal) != string::npos;
    }
};

int main() {
    vector<pair<string, string>> testCases = {
        {"abcde", "cdeab"},
        {"abcde", "abced"},
    };
    for (auto &t : testCases)
        cout << Solution().rotateString(t.first, t.second) << endl;
    return 0;
}
