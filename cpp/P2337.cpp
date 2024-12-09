#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> tc_type;

class Solution {
   public:
    bool canChange(string start, string target) {
        if (start == target) {
            return true;
        }
        int waitL = 0;
        int waitR = 0;

        for (int i = 0; i < start.length(); i++) {
            char curr = start[i];
            char goal = target[i];
            if (curr == 'R') {
                if (waitL > 0) {
                    return false;
                }
                waitR++;
            }
            if (goal == 'L') {
                if (waitR > 0) {
                    return false;
                }
                waitL++;
            }
            if (goal == 'R') {
                if (waitR == 0) {
                    return false;
                }
                waitR--;
            }
            if (curr == 'L') {
                if (waitL == 0) {
                    return false;
                }
                waitL--;
            }
        }
        return waitL == 0 && waitR == 0;
    }
};

int main() {
    vector<tc_type> testCases = {
        {"_L__R__R_", "L______RR"},
        {"R_L_", "__LR"},
        {"_R", "R_"},
    };

    for (auto &t : testCases)
        cout << Solution().canChange(t.first, t.second) << endl;

    return 0;
}
