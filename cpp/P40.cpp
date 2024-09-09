#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

typedef pair<vector<int>, int> testcase;

class Solution {
    map<int, int> coinsFreq;
    vector<int> distinctCoins;
    set<vector<int>> allSolutions;

    void coinHelper(vector<int>& curr, int i, int target) {
        if (target == 0) {
            allSolutions.insert(curr);
            return;
        }
        if (target < 0 || i >= distinctCoins.size()) {
            return;
        }

        for (int j = 0; j <= coinsFreq[distinctCoins[i]]; j++) {
            for (int k = 0; k < j; k++) {
                curr.push_back(distinctCoins[i]);
            }
            coinHelper(curr, i + 1, target - j * distinctCoins[i]);
            for (int k = 0; k < j; k++) {
                curr.pop_back();
            }
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // reset values
        coinsFreq = {};
        distinctCoins = {};
        allSolutions = {};

        for (int coin : candidates) {
            coinsFreq[coin]++;
        }
        for (auto it : coinsFreq) {
            distinctCoins.push_back(it.first);
        }

        // call recursive
        vector<int> currSol;
        coinHelper(currSol, 0, target);

        return vector<vector<int>>(allSolutions.begin(), allSolutions.end());
    }
};

int main() {
    vector<testcase> cases = {
        {{10, 1, 2, 7, 6, 1, 5}, 8},
        {{2, 5, 2, 1, 2}, 5},
        {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
         30}};
    Solution sol;

    for (auto& tc : cases) {
        vector<vector<int>> coins = sol.combinationSum2(tc.first, tc.second);
        printVecOfVector(coins);
    }

    return 0;
}
