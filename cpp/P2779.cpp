#include <bits/stdc++.h>
using namespace std;

typedef pair<vector<int>, int> tc_type;

class Solution {
   public:
    int maximumBeauty(vector<int>& nums, int k) {
        int numsSize = nums.size();
        pair<int, char> rangePoints[2 * numsSize];
        for (int i = 0; i < numsSize; i++) {
            rangePoints[2 * i] = {nums[i] - k, 'l'};
            rangePoints[2 * i + 1] = {nums[i] + k, 'r'};
        }
        sort(rangePoints, rangePoints + 2 * numsSize);

        int maxOverlap = 0, count = 0;
        for (int i = 0; i < 2 * numsSize; i++) {
            if (rangePoints[i].second == 'l')
                count++;
            else
                count--;
            maxOverlap = max(maxOverlap, count);
        }
        return maxOverlap;
    }
};

int main() {
    vector<tc_type> testCases = {
        {{4, 6, 1, 2}, 2},
        {{1, 1, 1, 1}, 10},
    };

    for (auto& t : testCases)
        cout << Solution().maximumBeauty(t.first, t.second) << endl;

    return 0;
}
