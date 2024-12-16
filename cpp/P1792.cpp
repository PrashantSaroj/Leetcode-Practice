#include <bits/stdc++.h>
using namespace std;

typedef pair<vector<vector<int>>, int> tc_type;

class Room {
    int pass, total;

   public:
    Room() { pass = total = 0; }

    Room(int pass, int total) {
        this->pass = pass;
        this->total = total;
    }

    inline double getRatio() const { return pass * 1.0 / total; }

    Room addStudent() {
        return Room(pass + 1, total + 1);
    }

    inline double calcChange() {
        return addStudent().getRatio() - getRatio();
    }

    bool operator()(Room& r1, Room& r2) {
        return r1.calcChange() < r2.calcChange();
    }
};

class Solution {
   public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Room, vector<Room>, Room> maxChangeHeap;
        for (auto& cl : classes)
            maxChangeHeap.push(Room(cl[0], cl[1]));

        while (extraStudents--) {
            Room maxChange = maxChangeHeap.top();
            maxChangeHeap.pop();
            maxChangeHeap.push(maxChange.addStudent());
        }

        double maxRatio = 0.0;
        while (!maxChangeHeap.empty()) {
            maxRatio += (maxChangeHeap.top().getRatio());
            maxChangeHeap.pop();
        }
        return maxRatio / classes.size();
    }
};

int main() {
    vector<tc_type> testCases = {
        {{{1, 2}, {3, 5}, {2, 2}}, 2},
        {{{2, 4}, {3, 9}, {4, 5}, {2, 10}}, 4},
    };

    for (auto& t : testCases)
        cout << Solution().maxAverageRatio(t.first, t.second) << endl;
    return 0;
}
