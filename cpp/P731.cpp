#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> interval;

class MyCalendarTwo {
    vector<interval> singleEvents, doubleEvents;

    bool intersect(interval i1, interval i2) {
        if (i1.first > i2.first) {
            return intersect(i2, i1);
        }
        return i1.second > i2.first;
    }

   public:
    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        interval curr(start, end);
        for (interval i : doubleEvents) {
            if (intersect(curr, i)) {
                return false;
            }
        }

        for (interval i : singleEvents) {
            if (intersect(curr, i)) {
                int start = max(i.first, curr.first);
                int end = min(i.second, curr.second);
                doubleEvents.push_back(interval(start, end));
            }
        }
        singleEvents.push_back(curr);
        return true;
    }
};

int main() {
    return 0;
}
