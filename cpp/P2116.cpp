#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canBeValid(string& s, string& locked) {
        int N = s.size();
        if (N & 1) {
            return false;
        }

        deque<int> lockedOpen, unlocked;
        for (int i = 0; i < N; i++) {
            if (locked[i] == '0') {
                unlocked.push_back(i);
            } else {
                if (s[i] == '(') {
                    lockedOpen.push_back(i);
                } else {
                    if (lockedOpen.size()) {
                        lockedOpen.pop_back();
                    } else if (unlocked.size()) {
                        unlocked.pop_front();
                    } else {
                        return false;
                    }
                }
            }
        }

        while (lockedOpen.size()) {
            int cur = lockedOpen.front(), flagMatched = 0;
            while (unlocked.size()) {
                int curUnlocked = unlocked.front();
                unlocked.pop_front();
                if (curUnlocked > cur) {
                    flagMatched = 1;
                    break;
                }
            }
            if (!flagMatched) {
                return false;
            }
            lockedOpen.pop_front();
        }

        return true;
    }
};

int main() {
    vector<pair<string, string>> testCases = {
        {"))()))", "010100"},
        {"()()", "0000"},
        {")", "0"},
    };

    for (auto& t : testCases)
        cout << Solution().canBeValid(t.first, t.second) << endl;
    return 0;
}
