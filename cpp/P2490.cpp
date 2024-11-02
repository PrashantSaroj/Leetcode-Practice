#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isCircularSentence(string sentence) {
        // for the first and last word
        int charCount = sentence.size();
        if (sentence[0] != sentence[charCount - 1]) {
            return false;
        }

        for (int i = 1; i < charCount; i++) {
            if (sentence[i] == ' ') {
                if (sentence[i - 1] != sentence[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<string> testCases = {
        "leetcode exercises sound delightful",
        "eetcode",
        "Leetcode is cool",
    };

    for (string &t : testCases)
        cout << Solution().isCircularSentence(t) << endl;

    return 0;
}
