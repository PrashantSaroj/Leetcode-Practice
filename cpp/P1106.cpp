#include <bits/stdc++.h>
using namespace std;

class Solution {
    string expression;

    bool evalExpr(int l, int r) {
        if (l == r) return expression[l] == 't' ? true : false;

        char curOp = expression[l];
        // change boundaries to exclude brackets
        l += 2;
        r -= 1;
        switch (curOp) {
            case '&':
                return evalAND(l, r);
            case '|':
                return evalOR(l, r);
            default:
                // not operator
                return !evalExpr(l, r);
        }
    }

    bool evalAND(int l, int r) {
        int i = l, openBraces = 0;
        for (; i <= r; i++)
            if (expression[i] == ',' && !openBraces) {
                bool subExpr = evalExpr(l, i - 1);
                // short circuiting
                if (!subExpr) return false;
                l = i + 1;
            } else if (expression[i] == '(') {
                openBraces++;
            } else if (expression[i] == ')') {
                openBraces--;
            }

        // last sub expression doesn't get computed in loop
        return evalExpr(l, r) ? true : false;
    }

    bool evalOR(int l, int r) {
        int i = l, openBraces = 0;
        for (; i <= r; i++)
            if (expression[i] == ',' && !openBraces) {
                bool subExpr = evalExpr(l, i - 1);
                // short circuiting
                if (subExpr) return true;
                l = i + 1;
            } else if (expression[i] == '(') {
                openBraces++;
            } else if (expression[i] == ')') {
                openBraces--;
            }

        // last sub expression doesn't get computed in loop
        return evalExpr(l, r) ? true : false;
    }

   public:
    bool parseBoolExpr(string expression) {
        this->expression = expression;
        return evalExpr(0, expression.size() - 1);
    }
};

int main() {
    vector<string> testCases = {"|(&(t,f,t),!(t))", "&(|(f))", "|(f,f,f,t)", "!(&(f,t))"};

    for (string &s : testCases) {
        cout << Solution().parseBoolExpr(s) << endl;
    }
    return 0;
}
