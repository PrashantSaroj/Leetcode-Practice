#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> nextMin, nextMax;

    void preProcessMinMax(vector<int>& nums, int minK, int maxK) {
        int N = nums.size(), curNextMin = N, curNextMax = N;
        nextMin.resize(N, 0);
        nextMax.resize(N, 0);
        for (int i = N - 1; i >= 0; i--) {
            if (nums[i] == minK) curNextMin = i;
            if (nums[i] == maxK) curNextMax = i;
            nextMax[i] = curNextMax;
            nextMin[i] = curNextMin;
        }
    }

    long long countInsideWin(vector<int>& nums, int start, int end) {
        long long res = 0;
        for (int l = start; l < end; l++) {
            int r = max(nextMax[l], nextMin[l]);
            if (r >= end) break;
            res += (end - r);
        }
        return res;
    }

   public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        preProcessMinMax(nums, minK, maxK);

        long long res = 0;
        for (int start = 0, N = nums.size(); start < N;) {
            // end is exclusive
            int end = start;
            while (end < N && nums[end] >= minK && nums[end] <= maxK) end++;
            res += countInsideWin(nums, start, end);
            start = end + 1;
        }
        return res;
    }
};

typedef tuple<vector<int>, int, int> tc_type;
int main() {
    vector<tc_type> testCases = {
        {{1, 3, 5, 2, 7, 5}, 1, 5},
        {{1, 1, 1, 1}, 1, 1},
    };
    for (auto& t : testCases)
        printf("Fixed bound subarrays: %lld\n", Solution().countSubarrays(get<0>(t), get<1>(t), get<2>(t)));
}
