#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res = 0, total = 0;
        for (int i = 0, j = 0; j < n; j++) {
            total += nums[j];
            while (i <= j && total * (j - i + 1) >= k) {
                total -= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{2, 1, 4, 3, 5}, 10},
        {{1, 1, 1}, 5},
    };
    for (auto& t : testCases)
        printf("# SubArrays: %lld\n", Solution().countSubarrays(t.first, t.second));
}
