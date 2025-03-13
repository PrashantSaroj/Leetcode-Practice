#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int N = nums.size();
        vector<int> rangeCumulator(N + 1, 0);
        for (int i = 0; i <= k; i++) {
            rangeCumulator[queries[i][0]] += queries[i][2];
            rangeCumulator[queries[i][1] + 1] -= queries[i][2];
        }

        int cumSum = 0;
        for (int i = 0; i < N; i++) {
            cumSum += rangeCumulator[i];
            if (cumSum < nums[i]) return false;
        }
        return true;
    }

   public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if (!accumulate(nums.begin(), nums.end(), 0)) return 0;

        int smallestK = -2;
        int l = 0, r = queries.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (isZeroArray(nums, queries, mid)) {
                r = mid - 1;
                smallestK = mid;
            } else {
                l = mid + 1;
            }
        }
        return smallestK + 1;
    }
};

int main() {
    vector<pair<vector<int>, vector<vector<int>>>> testCases = {
        {{2, 0, 2}, {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}}},
        {{4, 3, 2, 1}, {{1, 3, 2}, {0, 2, 1}}},
        {{7, 6, 8}, {{0, 0, 2}, {0, 1, 5}, {2, 2, 5}, {0, 2, 4}}},
    };

    for (auto& t : testCases)
        cout << Solution().minZeroArray(t.first, t.second) << endl;
}
