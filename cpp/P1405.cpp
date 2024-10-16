#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> icPair;

class Solution {
    const int ALPHA_SIZE = 3;

    inline bool lastTwoCharCheck(char c, char c0, char c1, int count) {
        return (c0 != c || c1 != c) && count > 0;
    }

   public:
    string longestDiverseString(int a, int b, int c) {
        vector<char> happy;
        char c0 = '\0', c1 = '\0';

        icPair charCount[] = {{a, 'a'}, {b, 'b'}, {c, 'c'}};

        while (1) {
            bool charUsedFlag = false;
            sort(charCount, charCount + ALPHA_SIZE);
            for (int i = ALPHA_SIZE - 1; i >= 0; i--) {
                int count = charCount[i].first;
                char c = charCount[i].second;
                if (lastTwoCharCheck(c, c0, c1, count)) {
                    happy.push_back(c);
                    charCount[i] = {count - 1, c};
                    c0 = c1;
                    c1 = c;
                    charUsedFlag = true;
                    break;
                }
            }

            if (!charUsedFlag)
                break;
        }

        return string(happy.begin(), happy.end());
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 1, 7},
        {7, 1, 0},
        {0, 0, 0},
    };
    for (auto &tc : testCases) {
        cout << Solution().longestDiverseString(tc[0], tc[1], tc[2]) << endl;
    }
    return 0;
}
