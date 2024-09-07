#include <bits/stdc++.h>
using namespace std;

class Solution {
    double myPowPositive(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        double ans = myPowPositive(x, n >> 1);
        if (n & 1) {
            ans = ans * ans * x;
        } else {
            ans = ans * ans;
        }
        return ans;
    }

   public:
    double myPow(double x, int n) {
        if (n < 0) {
            return myPowPositive(1.0 / x, -n);
        }
        return myPowPositive(x, n);
    }
};

int main() {
    vector<pair<double, int>> testCases = {
        {2.0, 10},
        {2.1, 3},
        {2.0, -2},
    };

    Solution sol;

    for (auto &tc : testCases) {
        cout << sol.myPow(tc.first, tc.second) << endl;
    }

    return 0;
}
