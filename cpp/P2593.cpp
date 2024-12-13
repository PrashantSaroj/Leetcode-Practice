#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> element;

class Solution {
   public:
    long long findScore(vector<int>& nums) {
        map<element, vector<element>> sortedMap;
        for (int i = 0, N = nums.size(); i < N; i++) {
            vector<element> curAdj = {};
            if (i - 1 >= 0) {
                curAdj.push_back({nums[i - 1], i - 1});
            }
            if (i + 1 < N) {
                curAdj.push_back({nums[i + 1], i + 1});
            }
            sortedMap[{nums[i], i}] = curAdj;
        }

        long long score = 0;
        while (!sortedMap.empty()) {
            auto cur = sortedMap.begin();
            score += (*cur).first.first;
            for (auto adj : (*cur).second) sortedMap.erase(adj);
            sortedMap.erase(cur);
        }
        return score;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {2, 1, 3, 4, 5, 2},
        {2, 3, 5, 1, 3, 2},
    };

    for (auto& t : testCases)
        cout << Solution().findScore(t) << endl;

    return 0;
}
