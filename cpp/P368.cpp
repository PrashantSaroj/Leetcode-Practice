#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
    vector<int> constructSubset(vector<int>& nums, vector<int>& lens, int maxInd) {
        vector<int> subset(1, nums[maxInd]);
        for (int j = maxInd - 1; j >= 0; j--) {
            if (lens[j] == lens[maxInd] - 1 && nums[maxInd] % nums[j] == 0) {
                maxInd = j;
                subset.push_back(nums[j]);
            }
        }
        return subset;
    }

   public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        vector<int> subsetLen(N, 1);
        int maxLen = 1, maxInd = 0;
        // sort array for dp
        sort(nums.begin(), nums.end());
        for (int i = 1; i < N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    subsetLen[i] = max(subsetLen[i], 1 + subsetLen[j]);
                }
            }
            // update the max variables
            if (subsetLen[i] > maxLen) {
                maxInd = i;
                maxLen = subsetLen[i];
            }
        }
        return constructSubset(nums, subsetLen, maxInd);
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3},
        {1, 2, 4, 8},
    };
    for (auto& t : testCases) printVector(Solution().largestDivisibleSubset(t));
}
