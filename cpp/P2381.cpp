#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

typedef pair<string, vector<vector<int>>> tc_type;

class Solution {
    inline char shiftChar(char c, int shift) {
        return (((c - 'a') + shift) % 26 + 26) % 26 + 'a';
    }

   public:
    string shiftingLetters(string& s, vector<vector<int>>& shifts) {
        int N = s.size();
        vector<int> cumShifts(N + 1, 0);

        for (auto& curShift : shifts) {
            int shiftDir = curShift[2] ? 1 : -1;
            cumShifts[curShift[0]] += shiftDir;
            cumShifts[curShift[1] + 1] += -shiftDir;
        }

        int shiftCount = 0;
        for (int i = 0; i < N; i++) {
            shiftCount += cumShifts[i];
            s[i] = shiftChar(s[i], shiftCount);
        }
        return s;
    }
};

int main() {
    vector<tc_type> testCases = {
        {"abc", {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}}},
        {"dztz", {{0, 0, 0}, {1, 1, 1}}},
    };

    for (auto& t : testCases)
        cout << Solution().shiftingLetters(t.first, t.second) << endl;
    return 0;
}
