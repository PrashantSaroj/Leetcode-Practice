#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> interval;

class MyCalendar {
    vector<interval> events;

    bool intersect(interval i1, interval i2) {
        if (i1.first > i2.first) {
            return intersect(i2, i1);
        }
        return i1.second > i2.first;
    }

   public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        interval currEvent(start, end);
        for (auto event : events) {
            if (intersect(event, currEvent)) {
                return false;
            }
        }
        events.push_back(currEvent);
        return true;
    }
};

int main() {
    return 0;
}
