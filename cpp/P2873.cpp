#include <bits/stdc++.h>
using namespace std;

class Solution {
    set<int> negNums, posNums;

    void addNum(int n) {
        if (n >= 0)
            posNums.insert(n);
        else
            negNums.insert(n);
    }

   public:
    long long maximumTripletValue(vector<int>& nums) {
        int N = nums.size();
        long long maxTriple = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    long long cur = ((long long)nums[k]) * (nums[i] - nums[j]);
                    maxTriple = max(maxTriple, cur);
                }
            }
        }
        return maxTriple;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {12, 6, 1, 2, 7},
        {1, 10, 3, 4, 19},
        {1, 2, 3},
    };
    for (auto& t : testCases) cout << Solution().maximumTripletValue(t) << endl;
}
