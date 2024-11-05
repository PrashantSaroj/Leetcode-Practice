#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minChanges(string s) {
        int changes = 0;
        for (int i = 0, N = s.size(); i < N; i += 2) {
            if (s[i] != s[i + 1]) {
                changes += 1;
            }
        }
        return changes;
    }
};

int main() {
    vector<string> testCases = {
        "1001",
        "10",
        "0000",
    };

    for (string s : testCases)
        cout << Solution().minChanges(s) << endl;

    return 0;
}
