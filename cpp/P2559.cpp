#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

typedef pair<vector<string>, vector<vector<int>>> tc_type;

class Solution {
    inline bool isVowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }

    inline bool isVowelString(string& s) {
        return isVowel(s[0]) && isVowel(s[s.size() - 1]);
    }

   public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int wordsCount = words.size(), queriesCount = queries.size();
        vector<int> cumSum(wordsCount + 1, 0);

        // compute prefix sum
        for (int i = 0; i < wordsCount; i++)
            cumSum[i + 1] = cumSum[i] + isVowelString(words[i]);

        vector<int> result;
        for (auto& q : queries)
            result.push_back(cumSum[q[1] + 1] - cumSum[q[0]]);

        return result;
    }
};

int main() {
    vector<tc_type> testCases = {
        {{"aba", "bcb", "ece", "aa", "e"}, {{0, 2}, {1, 4}, {1, 1}}},
        {{"a", "e", "i"}, {{0, 2}, {0, 1}, {2, 2}}},
    };

    for (auto& t : testCases)
        printVector(Solution().vowelStrings(t.first, t.second));

    return 0;
}
