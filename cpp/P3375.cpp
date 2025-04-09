#include <bits/stdc++.h>
using namespace std;

#define NUMS_SZ 101

class Solution {
    bitset<NUMS_SZ> existsNum;

   public:
    int minOperations(vector<int> &nums, int k) {
        int minNums = *min_element(nums.begin(), nums.end());
        if (minNums < k) return -1;

        for (int n : nums) existsNum[n] = 1;
        // return number of elements greater than k
        int ops = 0;
        for (int i = k + 1; i < NUMS_SZ; i++) ops += existsNum[i];
        return ops;
    }
};

typedef pair<vector<int>, int> tc_type;
int main() {
    vector<tc_type> testCases = {
        {{5, 2, 5, 4, 5}, 2},
        {{2, 1, 2}, 2},
        {{9, 7, 5, 3}, 1},
    };
    for (auto &t : testCases) cout << Solution().minOperations(t.first, t.second) << endl;
}
