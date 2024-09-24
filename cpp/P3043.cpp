#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    vector<TrieNode*> child;

    TrieNode() {
        child = vector<TrieNode*>(10, nullptr);
    }
};

class Trie {
    TrieNode head;

   public:
    void insert(int n) {
        string strN = to_string(n);
        TrieNode* it = &head;

        for (char c : strN) {
            int childIndex = c - '0';
            if (!(it->child)[childIndex]) {
                (it->child)[childIndex] = new TrieNode();
            }
            it = (it->child)[childIndex];
        }
    }

    int prefixLen(int n) {
        string strN = to_string(n);
        TrieNode* it = &head;
        int preLen = 0;

        for (char c : strN) {
            int childIndex = c - '0';
            if (!(it->child)[childIndex]) {
                break;
            }
            it = (it->child)[childIndex];
            preLen++;
        }
        return preLen;
    }
};

class Solution {
   public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie1;
        for (int n : arr1) {
            trie1.insert(n);
        }
        int maxPreLen = 0;
        for (int n : arr2) {
            maxPreLen = max(maxPreLen, trie1.prefixLen(n));
        }
        return maxPreLen;
    }
};

int main() {
    vector<int> arr1 = {1, 10, 100};
    vector<int> arr2 = {0};

    cout << Solution().longestCommonPrefix(arr1, arr2) << endl;

    return 0;
}
