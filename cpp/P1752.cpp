#include <bits/stdc++.h>
using namespace std;

class Solution {
    int findRotationPoint(vector<int>& nums) {
        for (int i = 1, N = nums.size(); i < N; i++) {
            if (nums[i] < nums[i - 1]) return i;
        }
        return 0;
    }

   public:
    bool check(vector<int>& nums) {
        int sortStart = findRotationPoint(nums), N = nums.size();
        for (int i = 0; i < N - 1; i++) {
            int cur = (i + sortStart) % N;
            int nex = (i + sortStart + 1) % N;
            if (nums[cur] > nums[nex]) return false;
        }
        return true;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {3, 4, 5, 1, 2},
        {2, 1, 3, 4},
        {1, 2, 3},
    };

    for (auto& t : testCases)
        cout << Solution().check(t) << endl;

    return 0;
}
