#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumCount(vector<int>& nums) {
        auto l = lower_bound(nums.begin(), nums.end(), 0);
        auto r = upper_bound(nums.begin(), nums.end(), 0);
        return max(l - nums.begin(), nums.end() - r);
    }
};

int main() {
    vector<vector<int>> testCases = {
        {-2, -1, -1, 1, 2, 3},
        {-3, -2, -1, 0, 0, 1, 2},
        {5, 20, 66, 1314},
    };

    for (auto& t : testCases)
        cout << Solution().maximumCount(t) << endl;
}
