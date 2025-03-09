#include <bits/stdc++.h>
using namespace std;

class Solution {
    int firstWindowWCount(string& blocks, int k) {
        int whiteCount = 0;
        for (int i = 0; i < k; i++)
            whiteCount += blocks[i] == 'W';
        return whiteCount;
    }

   public:
    int minimumRecolors(string& blocks, int k) {
        int minWhite = firstWindowWCount(blocks, k);
        int curWhite = minWhite;
        for (int i = k, N = blocks.size(); i < N; i++) {
            if (blocks[i] != blocks[i - k]) {
                if (blocks[i] == 'W') {
                    curWhite++;
                } else {
                    curWhite--;
                    minWhite = min(minWhite, curWhite);
                }
            }
        }
        return minWhite;
    }
};

int main() {
    vector<pair<string, int>> testCases = {
        {"WBBWWBBWBW", 7},
        {"WBWBBBW", 2},
    };

    for (auto& t : testCases)
        cout << Solution().minimumRecolors(t.first, t.second) << endl;

    return 0;
}
