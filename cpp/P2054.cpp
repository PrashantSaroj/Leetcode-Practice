#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> tc_type;

bool comp(const vector<int> range1, const vector<int> range2) {
    return range1[1] < range2[0];
}

class Solution {
   public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // sort by start times
        sort(events.begin(), events.end());

        // calculate prefix max
        int N = events.size();
        int prefMax[N];
        prefMax[N - 1] = events[N - 1][2];
        for (int i = N - 2; i >= 0; i--) {
            prefMax[i] = max(prefMax[i + 1], events[i][2]);
        }

        int maxValue = 0;
        for (auto& e : events) {
            int curMax = e[2];
            auto ub = upper_bound(events.begin(), events.end(), e, comp);
            if (ub != events.end()) {
                curMax += prefMax[ub - events.begin()];
            }
            maxValue = max(maxValue, curMax);
        }
        return maxValue;
    }
};

int main() {
    vector<tc_type> testCases = {
        {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}},
        {{1, 3, 2}, {4, 5, 2}, {1, 5, 5}},
        {{1, 5, 3}, {1, 5, 1}, {6, 6, 5}},
    };

    for (auto& t : testCases)
        cout << Solution().maxTwoEvents(t) << endl;

    return 0;
}
