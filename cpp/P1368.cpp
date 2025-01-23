#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minCost(vector<vector<int>>& grid) {
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}},
        {{1, 1, 3}, {3, 2, 2}, {1, 1, 4}},
        {{1, 2}, {4, 3}},
    };

    for (auto& t : testCases)
        cout << Solution().minCost(t) << endl;
    return 0;
}
