#include <bits/stdc++.h>
using namespace std;

typedef pair<int, vector<vector<int>>> tcType;

class Solution {
   public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> champion(n, true);
        for (auto& e : edges)
            champion[e[1]] = false;

        int champCount = 0, champ = -1;
        for (int i = 0; i < n; i++) {
            if (champion[i]) {
                champ = i;
                champCount++;
            }
        }

        return champCount == 1 ? champ : -1;
    }
};

int main() {
    vector<tcType> testCases = {
        {3, {{0, 1}, {1, 2}}},
        {4, {{0, 2}, {1, 3}, {1, 2}}},
    };

    for (auto& t : testCases)
        cout << Solution().findChampion(t.first, t.second) << endl;
    return 0;
}
