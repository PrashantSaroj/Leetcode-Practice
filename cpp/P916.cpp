#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

const int ALPHA_SZ = 26;

class Solution {
    vector<int> getFreq(string& word) {
        vector<int> freq(ALPHA_SZ, 0);
        for (char c : word)
            freq[c - 'a'] += 1;
        return freq;
    }

    void combineVecs(vector<int>& cur, vector<int>& res) {
        for (int i = 0; i < ALPHA_SZ; i++)
            res[i] = max(res[i], cur[i]);
    }

    bool isUniversal(string& word, vector<int>& combined) {
        vector<int> wordFreq = getFreq(word);
        for (int i = 0; i < ALPHA_SZ; i++)
            if (wordFreq[i] < combined[i]) return false;
        return true;
    }

   public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> combined(ALPHA_SZ, 0);
        for (auto& word : words2) {
            vector<int> cur = getFreq(word);
            combineVecs(cur, combined);
        }

        vector<string> universalWords;
        for (auto& word : words1)
            if (isUniversal(word, combined)) universalWords.push_back(word);
        return universalWords;
    }
};

int main() {
    vector<pair<vector<string>, vector<string>>> testCases = {
        {{"amazon", "apple", "facebook", "google", "leetcode"}, {"e", "o"}},
        {{"amazon", "apple", "facebook", "google", "leetcode"}, {"l", "e"}},
    };

    for (auto& t : testCases)
        printVector(Solution().wordSubsets(t.first, t.second));
    return 0;
}
