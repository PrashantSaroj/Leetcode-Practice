#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> braks;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                braks.push(c);
            } else {
                if (braks.empty()) {
                    return false;
                }

                char prev = braks.top();
                braks.pop();

                if (c == ')' && prev == '(') {
                    continue;
                }

                if (c == '}' && prev == '{') {
                    continue;
                }

                if (c == ']' && prev == '[') {
                    continue;
                }

                return false;
            }
        }
        return braks.empty();
    }
};

int main() {
    vector<string> testCases = {"()", "()[]{}", "(]", "([])"};
    Solution sol;

    for (string s : testCases) {
        cout << sol.isValid(s) << endl;
    }

    return 0;
}
