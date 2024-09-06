#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
    vector<vector<int>> permutations;
    void permuteRecurse(vector<int>& curNums, set<int>& remNums) {
        if (remNums.size() == 0) {
            permutations.push_back(curNums);
            return;
        }

        vector<int> firstNums(remNums.begin(), remNums.end());
        for (int n : firstNums) {
            remNums.erase(n);
            curNums.push_back(n);

            permuteRecurse(curNums, remNums);

            remNums.insert(n);
            curNums.pop_back();
        }
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        permutations = {};
        vector<int> curNums;
        set<int> remNums(nums.begin(), nums.end());
        permuteRecurse(curNums, remNums);
        return permutations;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3},
        {1, 2},
        {1},
        {}};
    Solution sol;

    for (vector<int>& nums : testCases) {
        vector<vector<int>> permutations = sol.permute(nums);
        printVecOfVector(permutations);
    }

    return 0;
}
