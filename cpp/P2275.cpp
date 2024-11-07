#include <bits/stdc++.h>
using namespace std;

#define INT_SZ 64

class Solution {
   public:
    int largestCombination(vector<int>& candidates) {
        // can do without extra memory as well
        vector<int> bitCount(INT_SZ, 0);
        for (int n : candidates) {
            for (int i = 0; i < INT_SZ; i++) {
                if (n & (1 << i)) {
                    bitCount[i]++;
                }
            }
        }
        return *max_element(bitCount.begin(), bitCount.end());
    }
};

int main() {
    vector<vector<int>> testCases = {
        {16, 17, 71, 62, 12, 24, 14},
        {8, 8},
    };

    for (auto& t : testCases)
        cout << Solution().largestCombination(t) << endl;

    return 0;
}
