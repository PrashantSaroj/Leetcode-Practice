#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int Q = queries.size(), N = nums.size();
        vector<int> rangeCumulator(N + 1, 0);
        for (int i = 0; i < Q; i++) {
            rangeCumulator[queries[i][0]] += 1;
            rangeCumulator[queries[i][1] + 1] -= 1;
        }

        int cumSum = 0;
        for (int i = 0; i < N; i++) {
            cumSum += rangeCumulator[i];
            if (cumSum < nums[i]) return false;
        }
        return true;
    }
};

int main() {
    vector<pair<vector<int>, vector<vector<int>>>> testCases = {
        {{1, 0, 1}, {{0, 2}}},
        {{4, 3, 2, 1}, {{1, 3}, {0, 2}}},
    };

    for (auto& t : testCases)
        cout << Solution().isZeroArray(t.first, t.second) << endl;
    return 0;
}
