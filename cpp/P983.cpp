#include <bits/stdc++.h>
using namespace std;

typedef pair<vector<int>, vector<int>> tc_type;

class Solution {
    int daysCount;
    vector<int> dp;
    const vector<int> passDurations = {1, 7, 30};

    int consumPass(vector<int>& days, int start, int pass) {
        int coveredDays = days[start] + pass;
        while (start < daysCount && days[start] < coveredDays) start++;
        return start;
    }

    int minCostRecur(vector<int>& days, vector<int>& costs, int start) {
        if (start >= daysCount) return 0;
        if (dp[start] != -1) return dp[start];

        int day1Pass = costs[0] + minCostRecur(days, costs, consumPass(days, start, 1));
        int day7Pass = costs[1] + minCostRecur(days, costs, consumPass(days, start, 7));
        int day30Pas = costs[2] + minCostRecur(days, costs, consumPass(days, start, 30));
        dp[start] = min(day1Pass, min(day7Pass, day30Pas));
        // cout << start << " " << dp[start] << endl;
        return dp[start];
    }

   public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        daysCount = days.size();
        dp = vector<int>(daysCount, -1);
        return minCostRecur(days, costs, 0);
    }
};

int main() {
    vector<tc_type> testCases = {
        {{1, 4, 6, 7, 8, 20}, {2, 7, 15}},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31}, {2, 7, 15}},
    };

    for (auto& t : testCases)
        cout << Solution().mincostTickets(t.first, t.second) << endl;
    return 0;
}
