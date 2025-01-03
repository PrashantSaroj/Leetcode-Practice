#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int waysToSplitArray(vector<int>& nums) {
        int N = nums.size();
        int prefixSum[N];
        prefixSum[0] = nums[0];

        for (int i = 1; i < N; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];

        int waysSplit = 0;
        for (int i = 0; i < N - 1; i++)
            if (prefixSum[i] >= (prefixSum[N - 1] - prefixSum[i])) waysSplit++;

        return waysSplit;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {10, 4, -8, 7},
        {2, 3, 1, 0},
    };

    for (auto& t : testCases)
        cout << Solution().waysToSplitArray(t) << endl;
    return 0;
}
