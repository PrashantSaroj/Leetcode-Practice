#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long chalkSum = k % accumulate(chalk.begin(), chalk.end(), 0L);
        for (int i = 0; i < chalk.size(); i++) {
            chalkSum -= chalk[i];
            if (chalkSum < 0) {
                return i;
            }
        }
        // error
        return -1;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {5, 1, 5},
        {3, 4, 1, 2}};
    vector<int> chalkCount = {22, 25};
    Solution sol;

    for (int i = 0; i < chalkCount.size(); i++) {
        cout << sol.chalkReplacer(testCases[i], chalkCount[i]) << endl;
    }

    return 0;
}
