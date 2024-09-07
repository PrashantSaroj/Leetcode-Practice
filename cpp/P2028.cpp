#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"

using namespace std;

class Solution {
   public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int rollSum = accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();
        int missingSum = (n + m) * mean - rollSum;

        if (missingSum < n || missingSum > 6 * n) {
            return vector<int>{};
        }

        vector<int> retRolls = vector<int>(n, 1);
        missingSum -= n;
        int i = 0;

        while (missingSum > 0) {
            int increment = missingSum >= 5 ? 5 : missingSum;
            retRolls[i] += increment;
            missingSum -= increment;
            i++;
        }

        return retRolls;
    }
};

int main() {
    int T = 3;
    vector<vector<int>> rolls = {
        {3, 2, 4, 3},
        {1, 5, 6},
        {1, 2, 3, 4}};
    vector<int> means = {4, 3, 6};
    vector<int> n = {2, 4, 4};

    Solution sol;

    for (int i = 0; i < T; i++) {
        printVector(sol.missingRolls(rolls[i], means[i], n[i]));
    }
    return 0;
}
