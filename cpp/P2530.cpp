#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        long long score = 0;
        while (k--) {
            int curMax = maxHeap.top();
            maxHeap.pop();
            score += curMax;
            maxHeap.push((curMax / 3 + (curMax % 3 != 0)));
        }
        return score;
    }
};

int main() {
    vector<int> nums = {1, 10, 3, 3, 3};
    int k = 3;

    cout << Solution().maxKelements(nums, k) << endl;

    return 0;
}
