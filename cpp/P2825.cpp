#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> tc_type;

class Solution {
    inline bool equalAfterRotating(char c1, char c2) {
        return c1 == 'z' ? c2 == 'a' : c1 + 1 == c2;
    }

   public:
    bool canMakeSubsequence(string str1, string str2) {
        int i1 = 0, i2 = 0;
        int N1 = str1.size(), N2 = str2.size();

        while (i1 < N1 && i2 < N2) {
            if (str1[i1] == str2[i2] || equalAfterRotating(str1[i1], str2[i2])) i2++;
            i1++;
        }

        return i2 == N2;
    }
};

int main() {
    vector<tc_type> testCases = {
        {"abc", "ad"},
        {"zc", "ad"},
        {"ab", "d"},
    };

    for (auto &t : testCases)
        cout << Solution().canMakeSubsequence(t.first, t.second) << endl;

    return 0;
}
