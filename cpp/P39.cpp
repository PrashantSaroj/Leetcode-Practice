#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

typedef pair<vector<int>, int> testcase;

class Solution {
    vector<int> coins;
    vector<vector<int>> allSolutions;

    void coinHelper(vector<int>& curr, int i, int target) {
        if (target == 0) {
            allSolutions.push_back(vector<int>(curr.begin(), curr.end()));
            return;
        }
        if (target < 0) {
            return;
        }

        curr.push_back(coins[i]);
        coinHelper(curr, i, target - coins[i]);
        curr.pop_back();

        if (i + 1 < coins.size()) {
            coinHelper(curr, i + 1, target);
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // reset values
        coins = candidates;
        allSolutions = {};

        // call recursive
        vector<int> currSol;
        coinHelper(currSol, 0, target);

        return allSolutions;
    }
};

int main() {
    vector<testcase> cases = {
        {{2, 3, 6, 7}, 7},
        {{2, 3, 5}, 8}};
    Solution sol;

    for (auto& tc : cases) {
        vector<vector<int>> coins = sol.combinationSum(tc.first, tc.second);
        printVecOfVector(coins);
    }

    return 0;
}
