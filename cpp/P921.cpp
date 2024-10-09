#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minAddToMakeValid(string s) {
        stack<char> balancer;
        int unbalancedClosing = 0;
        for (char c : s) {
            if (c == '(')
                balancer.push(c);
            else if (!balancer.empty())
                balancer.pop();
            else
                unbalancedClosing++;
        }
        return unbalancedClosing + balancer.size();
    }
};

int main() {
    vector<string> testCases = {
        "())",
        "(((",
        "((((((()))(((",
    };
    for (string tc : testCases) {
        cout << Solution().minAddToMakeValid(tc) << endl;
    }
    return 0;
}
