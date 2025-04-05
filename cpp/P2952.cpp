#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int addedCoins = 0, obtain = 0, i = 0;
        while (obtain <= target) {
            if (i < coins.size() && coins[i] <= obtain + 1) {
                obtain += coins[i++];
            } else {
                obtain += obtain + 1;
                addedCoins++;
            }
        }
        return addedCoins;
    }
};

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{100000}, 100000},
        {{1, 4, 10}, 19},
        {{1, 4, 10, 5, 7, 19}, 19},
        {{1, 1, 1}, 20},
    };
    for (auto& t : testCases) cout << Solution().minimumAddedCoins(t.first, t.second) << endl;
}
