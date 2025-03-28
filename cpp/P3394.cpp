#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> side;

class Solution {
    bool cutPossible(vector<side> &sides, int cuts = 2) {
        int totalCuts = 0;
        sort(sides.begin(), sides.end());
        int prevEnd = sides[0].second;
        for (int i = 1; i < sides.size(); i++) {
            if (sides[i].first >= prevEnd) totalCuts++;
            if (totalCuts == cuts) return true;
            prevEnd = max(prevEnd, sides[i].second);
        }
        return false;
    }

   public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles) {
        vector<side> xSides, ySides;
        for (auto &rec : rectangles) {
            xSides.push_back({rec[0], rec[2]});
            ySides.push_back({rec[1], rec[3]});
        }
        return cutPossible(xSides) || cutPossible(ySides);
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> testCases = {
        {4, {{0, 0, 1, 4}, {1, 0, 2, 3}, {2, 0, 3, 3}, {3, 0, 4, 3}, {1, 3, 4, 4}}},
        {5, {{1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}}},
        {4, {{0, 0, 1, 1}, {2, 0, 3, 4}, {0, 2, 2, 3}, {3, 0, 4, 3}}},
        {4, {{0, 2, 2, 4}, {1, 0, 3, 2}, {2, 2, 3, 4}, {3, 0, 4, 2}, {3, 2, 4, 4}}},
    };

    for (auto &t : testCases) {
        cout << Solution().checkValidCuts(t.first, t.second) << endl;
    }
}
