#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
#include "utils/StringUtils.cpp"

using namespace std;

class Solution {
   public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> sentences = {s1, s2};
        unordered_map<string, int> freq;
        for (auto &s : sentences) {
            vector<string> words = split(s);
            for (auto &w : words) {
                freq[w] += 1;
            }
        }

        vector<string> uncommon;
        for (auto it : freq) {
            if (it.second == 1) {
                uncommon.push_back(it.first);
            }
        }
        return uncommon;
    }
};

int main() {
    string s1 = "this apple is sweet", s2 = "this apple is sour";
    printVector(Solution().uncommonFromSentences(s1, s2));
    return 0;
}
