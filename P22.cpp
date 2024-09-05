#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
    vector<string> genRecurse(string curr, int remO, int remC) {
        // at any point # opening brackets >= # closing brackets
        if (remC == 0) {
            return vector<string>{curr};
        }

        if (remO == remC) {
            return genRecurse(curr + '(', remO - 1, remC);
        }

        if (remO == 0) {
            return vector<string>{curr + string(remC, ')')};
        }

        vector<string> branch1 = genRecurse(curr + '(', remO - 1, remC);
        vector<string> branch2 = genRecurse(curr + ')', remO, remC - 1);
        branch1.insert(branch1.end(), branch2.begin(), branch2.end());

        return branch1;
    }

   public:
    vector<string> generateParenthesis(int n) {
        return genRecurse("", n, n);
    }
};

int main() {
    vector<int> testCases = {1, 3};
    Solution sol;

    for (int t : testCases) {
        printVector(sol.generateParenthesis(t));
    }

    return 0;
}
