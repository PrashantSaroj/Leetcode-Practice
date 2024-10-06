#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
    int WORD_SZ, WIND_SZ;
    unordered_set<string> dictionary;
    vector<int> substrIndices;

    inline bool isInDict(string& w) {
        return dictionary.find(w) != dictionary.end();
    }

    void substringHelper(string& s, int wind_start, vector<string>& words) {
        int N = s.size();
        unordered_map<string, int> missing;
        for (string& w : words) missing[w] += 1;
        // init first window
        for (int i = wind_start; i < wind_start + WIND_SZ && i + WIND_SZ <= N; i += WORD_SZ) {
            string w = s.substr(i, WORD_SZ);
            if (isInDict(w)) {
                missing[w] -= 1;
                if (!missing[w]) missing.erase(w);
            }
        }

        int l = 0, r = 0;
        for (int i = wind_start; i + WIND_SZ <= N; i += WORD_SZ) {
            string l_word = s.substr(l, WORD_SZ);
            string r_word = s.substr(r, WORD_SZ);
            if (isInDict(l_word)) {
                missing[l_word] += 1;
                if (!missing[l_word]) missing.erase(l_word);
            }

            if (isInDict(r_word)) {
                missing[r_word] -= 1;
                if (!missing[r_word]) missing.erase(r_word);
            }

            if (!missing.size())
                substrIndices.push_back(i);
            l = i;
            r = i + WIND_SZ;
        }
    }

   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // initialisation of class variables
        WORD_SZ = words[0].size();
        WIND_SZ = WORD_SZ * words.size();
        dictionary = unordered_set<string>(words.begin(), words.end());
        substrIndices = {};

        for (int i = 0; i < WORD_SZ; i++) {
            substringHelper(s, i, words);
        }

        return substrIndices;
    }
};

int main() {
    vector<pair<string, vector<string>>> testCases = {
        {"bcabbcaabbccacacbabccacaababcbb", {"c", "b", "a", "c", "a", "a", "a", "b", "c"}},
        // {"barfoothefoobarman", {"foo", "bar"}},
        // {"wordgoodgoodgoodbestword", {"word", "good", "best", "word"}},
        // {"barfoofoobarthefoobarman", {"bar", "foo", "the"}},
    };

    for (auto& testCase : testCases) {
        printVector(Solution().findSubstring(testCase.first, testCase.second));
    }

    return 0;
}
