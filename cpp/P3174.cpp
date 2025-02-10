#include <bits/stdc++.h>
using namespace std;

class Solution {
    inline bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

   public:
    string clearDigits(string s) {
        deque<char> charStack;
        for (char c : s) {
            if (isDigit(c)) {
                if (!charStack.empty()) charStack.pop_back();
            } else {
                charStack.push_back(c);
            }
        }
        return string(charStack.begin(), charStack.end());
    }
};

int main() {
    vector<string> testCases = {
        "abc",
        "cb34",
    };

    for (auto &t : testCases)
        cout << Solution().clearDigits(t) << endl;
    return 0;
}
