#include <bits/stdc++.h>
using namespace std;

class Solution {
    int ALPHA_SZ = 26;

    vector<int> calcFreq(string& s) {
        vector<int> retVal(ALPHA_SZ, 0);
        for (char c : s)
            retVal[c - 'a'] += 1;
        return retVal;
    }

   public:
    int minimumLength(string& s) {
        vector<int> freq = calcFreq(s);
        int minLength = 0;
        for (int i = 0; i < ALPHA_SZ; i++) {
            if (freq[i]) {
                minLength += (freq[i] & 1 ? 1 : 2);
            }
        }
        return minLength;
    }
};

int main() {
    vector<string> testCases = {
        "abaacbcbb",
        "aa",
    };

    for (string& s : testCases)
        cout << Solution().minimumLength(s) << endl;
    return 0;
}
