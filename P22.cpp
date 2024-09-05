#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
    int n;
    vector<string> res;

    void genRecurse(string curr, int open, int close) {
        // at any point # opening brackets >= # closing brackets
        if (curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            genRecurse(curr + '(', open + 1, close);
        }

        if (close < open) {
            genRecurse(curr + ')', open, close + 1);
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        res = {};
        this->n = n;
        genRecurse("", 0, 0);
        return res;
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
