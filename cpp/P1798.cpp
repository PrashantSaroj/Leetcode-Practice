#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int maxConsecutive = 1;
        for (int n : coins) {
            if (n <= maxConsecutive) {
                maxConsecutive += n;
            } else {
                break;
            }
        }
        return maxConsecutive;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 3},
        {1, 1, 1, 4},
        {1, 4, 10, 3, 1},
    };
    for (auto& t : testCases) cout << Solution().getMaximumConsecutive(t) << endl;
}
