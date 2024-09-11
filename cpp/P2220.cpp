#include <bits/stdc++.h>
using namespace std;

#define INT_LEN 32

typedef pair<int, int> testcase;

class Solution {
   public:
    int minBitFlips(int start, int goal) {
        int xored = start ^ goal, flips = 0;
        for (int i = 0; i < INT_LEN; i++) {
            if (xored & 1) {
                flips++;
            }
            xored = xored >> 1;
        }
        return flips;
    }
};

int main() {
    vector<testcase> T = {{10, 7}, {3, 4}};
    Solution sol;

    for (auto t : T) {
        cout << sol.minBitFlips(t.first, t.second) << endl;
    }

    return 0;
}
