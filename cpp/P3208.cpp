#include <bits/stdc++.h>
using namespace std;

class Solution {
    int processFirstWindow(vector<int>& colors, int k) {
        int alterations = 0;
        for (int i = 1; i < k; i++)
            alterations += (colors[i] != colors[i - 1]);
        return alterations;
    }

   public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int totalColors = colors.size();
        int curWinAlter = processFirstWindow(colors, k);
        int groups = curWinAlter == k - 1;
        for (int i = 1; i < totalColors; i++) {
            // new element is different from last
            curWinAlter += (colors[(i + k - 1) % totalColors] != colors[(i + k - 2) % totalColors]);
            curWinAlter -= (colors[i - 1] != colors[i]);
            groups += (curWinAlter == k - 1);
        }
        return groups;
    }
};

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{0, 1, 0, 1, 0}, 3},
        {{0, 1, 0, 0, 1, 0, 1}, 6},
        {{1, 1, 0, 1}, 4},
    };

    for (auto& t : testCases)
        cout << Solution().numberOfAlternatingGroups(t.first, t.second) << endl;

    return 0;
}
