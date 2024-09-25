#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

struct TrieNode {
    int count = 0;
    TrieNode* child[26] = {nullptr};
};

class Trie {
    TrieNode head;

   public:
    void insert(string& word) {
        TrieNode* it = &head;

        for (char c : word) {
            int c_i = c - 'a';
            if (!(it->child)[c_i]) {
                (it->child)[c_i] = new TrieNode();
            }
            (it->child)[c_i]->count += 1;
            it = (it->child)[c_i];
        }
    }

    int calculateScore(string& word) {
        TrieNode* it = &head;
        int score = 0;

        // word is guaranteed to be present in the trie
        for (char c : word) {
            int c_i = c - 'a';
            score += (it->child)[c_i]->count;
            it = (it->child)[c_i];
        }
        return score;
    }
};

class Solution {
   public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie1;
        for (string& word : words) {
            trie1.insert(word);
        }
        vector<int> prefixScores;

        for (string& word : words) {
            prefixScores.push_back(trie1.calculateScore(word));
        }
        return prefixScores;
    }
};

int main() {
    vector<string> words = {"abc", "ab", "bc", "b"};
    vector<int> prefixScores = Solution().sumPrefixScores(words);

    printVector(prefixScores);
    return 0;
}
