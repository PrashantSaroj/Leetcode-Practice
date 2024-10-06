#include <bits/stdc++.h>

#include "utils/StringUtils.cpp"
using namespace std;

class Solution {
   public:
    bool areSentencesSimilar(string &sentence1, string &sentence2) {
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);

        if (words1.size() < words2.size()) {
            return areSentencesSimilar(sentence2, sentence1);
        }

        int n1 = words1.size(), i2 = 0, n2 = words2.size();
        // match some words at start
        while (i2 < n2 and words1[i2] == words2[i2]) i2++;
        // remaining must match at end
        while (i2 < n2 and words1[n1 - n2 + i2] == words2[i2]) i2++;
        return i2 == n2;
    }
};

typedef pair<string, string> tcType;

int main() {
    vector<tcType> testCases = {
        {"A B C", "A B"},
        {"A B C", "B C"},
        {"A a B b B", "A B"},
    };

    for (auto &tc : testCases) {
        cout << Solution().areSentencesSimilar(tc.first, tc.second) << endl;
    }
    return 0;
}
