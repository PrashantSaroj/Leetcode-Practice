#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> tc_type;

class Solution {
    bool isPrefix(string &sentence, string &searchWord, int start) {
        int iWord = 0, lWord = searchWord.size();
        int iSentence = start, lSentence = sentence.size();

        while (iWord < lWord && iSentence < lSentence) {
            if (sentence[iSentence] != searchWord[iWord]) break;
            iWord++;
            iSentence++;
        }
        return lWord == iWord;
    }

   public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordIndex = 1, searchFlag = 1;
        for (int i = 0, N = sentence.size(); i < N; i++) {
            if (searchFlag) {
                if (isPrefix(sentence, searchWord, i))
                    return wordIndex;
                else {
                    wordIndex++;
                    searchFlag = 0;
                }
            } else if (sentence[i] == ' ') {
                searchFlag = 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<tc_type> testCases = {
        {"i love eating burger", "burg"},
        {"this problem is an easy problem", "pro"},
        {"i am tired", "you"},
    };
    for (auto &t : testCases) {
        cout << Solution().isPrefixOfWord(t.first, t.second) << endl;
    }
    return 0;
}
