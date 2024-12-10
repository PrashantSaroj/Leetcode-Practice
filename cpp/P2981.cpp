#include <bits/stdc++.h>
using namespace std;

class Solution {
    int maxLength(string &s, char c) {
        map<int, int> lenFreq;

        int i = 0, N = s.size();
        while (i < N) {
            int start = i;
            if (s[i] == c) {
                while (i < N && s[i] == c) i++;
                int curLen = i - start;
                lenFreq[curLen] += 1;
                if (curLen > 1) lenFreq[curLen - 1] += 2;
                if (curLen > 2) lenFreq[curLen - 2] += 3;
            }
            i++;
        }

        for (auto it = lenFreq.rbegin(); it != lenFreq.rend(); it++) {
            if (it->second >= 3) return it->first;
        }

        return -1;
    }

   public:
    int maximumLength(string s) {
        int retVal = -1;
        for (int i = 'a'; i <= 'z'; i++)
            retVal = max(retVal, maxLength(s, i));

        return retVal;
    }
};

int main() {
    vector<string> testCases = {
        "aaaa",
        "abcdef",
        "abcaba",
    };

    for (auto &t : testCases)
        cout << Solution().maximumLength(t) << endl;

    return 0;
}
