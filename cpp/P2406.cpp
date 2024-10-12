#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minGroups(vector<vector<int>>& intervals) {
        int N = intervals.size(), i = 0;
        pair<int, int> cumArr[2 * N];
        for (auto& interval : intervals) {
            cumArr[i++] = {interval[0], 1};
            cumArr[i++] = {interval[1] + 1, -1};
        }
        sort(cumArr, cumArr + 2 * N);

        int curOverlap = 0, maxOverlap = 0;
        for (auto& t : cumArr) {
            curOverlap += t.second;
            maxOverlap = max(maxOverlap, curOverlap);
        }
        return maxOverlap;
    }
};

int main() {
    vector<vector<int>> intervals = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    cout << Solution().minGroups(intervals) << endl;

    return 0;
}
