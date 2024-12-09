#include <bits/stdc++.h>
using namespace std;

typedef tuple<vector<int>, int, int> tc_type;

class Solution {
   public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int chosenCount = 0;
        unordered_set<int> bannedSet(banned.begin(), banned.end());

        for (int i = 1; i <= n; i++) {
            if (i <= maxSum && bannedSet.find(i) == bannedSet.end()) {
                chosenCount++;
                maxSum -= i;
            }
        }

        return chosenCount;
    }
};

int main() {
    vector<tc_type> testCases = {
        {{1, 6, 5}, 5, 6},
        {{1, 2, 3, 4, 5, 6, 7}, 8, 1},
        {{11}, 7, 50},
    };

    for (auto& t : testCases)
        cout << Solution().maxCount(get<0>(t), get<1>(t), get<2>(t)) << endl;

    return 0;
}
