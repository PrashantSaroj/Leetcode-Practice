#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int MIN_IN_DAY = 24 * 60;
    const int MAX_DIFF = 12 * 60;

    int getMinutes(string &t) {
        int h = stoi(t.substr(0, 2)), m = stoi(t.substr(3, 2));
        return h * 60 + m;
    }

    int findDifference(string &t1, string &t2) {
        // maximum difference between any two time cannot be more than 12 hours
        int diff = abs(getMinutes(t1) - getMinutes(t2));
        return min(diff, MIN_IN_DAY - diff);
    }

   public:
    int findMinDifference(vector<string> &timePoints) {
        // Note: NlogN sorting is not needed (can be done in N using bitset)
        sort(timePoints.begin(), timePoints.end());
        int minDiff = MIN_IN_DAY, N = timePoints.size();
        for (int i = 0; i < N; i++) {
            minDiff = min(minDiff, findDifference(timePoints[i], timePoints[(i + 1) % N]));
        }
        return minDiff;
    }
};

int main() {
    vector<string> timePoints = {"00:00", "23:59"};
    cout << Solution().findMinDifference(timePoints) << endl;
    return 0;
}
