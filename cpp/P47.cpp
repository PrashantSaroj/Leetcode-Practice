#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
    int permLength;
    set<vector<int>> permutations;

    void permuteRecurse(vector<int>& curNums, map<int, int>& numFreq) {
        if (curNums.size() == permLength) {
            permutations.insert(curNums);
            return;
        }

        vector<int> firstNums;
        for (auto const& it : numFreq) {
            for (int i = 0; i < it.second; i++) {
                firstNums.push_back(it.first);
            }
        }

        for (int n : firstNums) {
            numFreq[n]--;
            curNums.push_back(n);

            permuteRecurse(curNums, numFreq);

            numFreq[n]++;
            curNums.pop_back();
        }
    }

   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permutations = {};
        permLength = nums.size();

        vector<int> curNums;
        map<int, int> numFreq;

        for (int n : nums) {
            numFreq[n]++;
        }

        permuteRecurse(curNums, numFreq);
        return vector<vector<int>>(permutations.begin(), permutations.end());
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3},
        {1, 1, 2}};
    Solution sol;

    for (vector<int>& nums : testCases) {
        vector<vector<int>> permutations = sol.permuteUnique(nums);
        printVecOfVector(permutations);
    }

    return 0;
}
