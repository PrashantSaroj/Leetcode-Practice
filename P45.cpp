#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

class Solution {
   public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        vector<int> minSteps(N, INF);
        minSteps[N - 1] = 0;

        for (int i = N - 2; i >= 0; i--) {
            for (int j = i + 1; j <= min(i + nums[i], N - 1); j++) {
                minSteps[i] = min(minSteps[i], 1 + minSteps[j]);
            }
        }

        return minSteps[0];
    }
};

int main() {
    vector<vector<int>> testCases = {
        {2, 3, 1, 1, 4},
        {2, 3, 0, 1, 4}};
    Solution sol;

    for (int i = 0; i < testCases.size(); i++) {
        cout << sol.jump(testCases[i]) << endl;
    }

    return 0;
}
