#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
   public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballPos;
        unordered_map<int, unordered_set<int>> colorBuckets;

        vector<int> result;
        for (auto& q : queries) {
            int ball = q[0], color = q[1];
            if (ballPos.find(ball) != ballPos.end()) {
                int oldPos = ballPos[ball];
                colorBuckets[oldPos].erase(ball);
                if (!colorBuckets[oldPos].size()) {
                    colorBuckets.erase(oldPos);
                }
            }
            ballPos[ball] = color;
            colorBuckets[color].insert(ball);

            result.push_back(colorBuckets.size());
        }
        return result;
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> testCases = {
        {4, {{1, 4}, {2, 5}, {1, 3}, {3, 4}}},
        {4, {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}}},
    };

    for (auto& t : testCases)
        printVector(Solution().queryResults(t.first, t.second));
    return 0;
}
