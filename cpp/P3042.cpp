#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPrefix(string& s1, string& s2) {
        int i1 = 0, i2 = 0;
        int N1 = s1.size(), N2 = s2.size();
        while (i1 < N1 && i2 < N2) {
            if (s1[i1] != s2[i2]) return false;
            i1++;
            i2++;
        }
        return i1 == N1;
    }

    bool isSufix(string& s1, string& s2) {
        int i1 = s1.size() - 1, i2 = s2.size() - 1;
        while (i1 >= 0 && i2 >= 0) {
            if (s1[i1] != s2[i2]) return false;
            i1--;
            i2--;
        }
        return i1 == -1;
    }

    bool isPrefixAndSuffix(string& s1, string& s2) {
        return isPrefix(s1, s2) && isSufix(s1, s2);
    }

   public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int goodPairs = 0;
        for (int i = 0, wordsCount = words.size(); i < wordsCount; i++) {
            for (int j = i + 1; j < wordsCount; j++) {
                goodPairs += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return goodPairs;
    }
};

int main() {
    vector<vector<string>> testCases = {
        {"a", "aba", "ababa", "aa"},
        {"pa", "papa", "ma", "mama"},
        {"abab", "ab"},
    };

    for (auto& t : testCases)
        cout << Solution().countPrefixSuffixPairs(t) << endl;
    return 0;
}
