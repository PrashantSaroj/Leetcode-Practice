#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minLength(string s) {
        stack<char> helper;
        for (char c : s) {
            if (!helper.empty()) {
                char l = helper.top();
                if (l == 'A' && c == 'B')
                    helper.pop();
                else if (l == 'C' && c == 'D')
                    helper.pop();
                else
                    helper.push(c);
            } else
                helper.push(c);
        }
        return helper.size();
    }
};

int main() {
    vector<string> testCases = {
        "ABFCACDB",
        "ACBBD",
        "AAAABBBBBB"};
    for (string t : testCases) {
        cout << Solution().minLength(t) << endl;
    }
    return 0;
}
