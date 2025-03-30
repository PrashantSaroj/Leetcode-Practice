#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
   public:
    int partitionString(string& s) {
        int numParts = 1, prevStart = 0;
        bitset<26> letterFreq;
        for (int i = 0; i < s.size(); i++) {
            if (letterFreq[s[i] - 'a']) {
                // duplicate detected
                numParts++;
                prevStart = i;
                letterFreq.reset();
            }
            letterFreq[s[i] - 'a'] = 1;
        }
        return numParts;
    }
};

int main() {
    vector<string> testCases = {
        "abacaba",
        "ssssss",
    };
    for (auto& t : testCases) cout << Solution().partitionString(t) << endl;
}
