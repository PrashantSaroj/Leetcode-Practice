#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> range;
class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<range, vector<range>, greater<range>> minHeap;
        for (auto& inter : intervals) minHeap.push({inter[1], inter[0]});

        int meetingsScheduled = 1;

        int scheduledEnd = minHeap.top().first;
        minHeap.pop();
        while (!minHeap.empty()) {
            range cur = minHeap.top();
            if (cur.second >= scheduledEnd) {
                // schedule new one
                meetingsScheduled++;
                scheduledEnd = cur.first;
            }
            minHeap.pop();
        }
        return intervals.size() - meetingsScheduled;
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}},
        {{1, 2}, {2, 3}, {3, 4}, {1, 3}},
        {{1, 2}, {1, 2}, {1, 2}},
        {{1, 2}, {2, 3}},
    };

    for (auto& t : testCases) {
        cout << Solution().eraseOverlapIntervals(t) << endl;
    }
}
