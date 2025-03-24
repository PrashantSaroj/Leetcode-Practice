#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> range;

class Solution {
    vector<range> flattenRanges(vector<range> meetings) {
        vector<range> flattened;
        range prev = meetings[0];
        for (int i = 1; i < meetings.size(); i++) {
            // if current's start is less than the previous end => intersection
            if (meetings[i].first <= prev.second) {
                prev.second = max(prev.second, meetings[i].second);
            } else {
                flattened.push_back(prev);
                prev = meetings[i];
            }
        }
        flattened.push_back(prev);
        return flattened;
    }

   public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<range> sortedMeetings;
        for (int i = 0; i < meetings.size(); i++) {
            sortedMeetings.push_back({meetings[i][0], meetings[i][1]});
        }
        sort(sortedMeetings.begin(), sortedMeetings.end());

        vector<range> flattenedMeetings = flattenRanges(sortedMeetings);
        // initialise with intial + final days
        int meetingFreeDays = (flattenedMeetings[0].first - 1) + (days - flattenedMeetings.back().second);
        for (int i = 1; i < flattenedMeetings.size(); i++) {
            meetingFreeDays += flattenedMeetings[i].first - flattenedMeetings[i - 1].second - 1;
        }
        return meetingFreeDays;
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> testCases = {
        {10, {{5, 7}, {1, 3}, {9, 10}}},
        {5, {{2, 4}, {1, 3}}},
        {6, {{1, 6}}},
    };

    for (auto& t : testCases) {
        cout << Solution().countDays(t.first, t.second) << endl;
    }
}
