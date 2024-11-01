#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

struct TrieNode {
    int wordIndex = -1;
    // extra char for '/'
    TrieNode* child[27] = {nullptr};
};

void insert(TrieNode* root, string& dir, int index) {
    TrieNode* it = root;
    for (char c : dir) {
        int childIndex = (c == '/' ? 26 : c - 'a');
        if (!it->child[childIndex]) {
            it->child[childIndex] = new TrieNode();
        }
        it = it->child[childIndex];
    }
    it->child[26] = new TrieNode({index});
}

class Solution {
   public:
    vector<string> removeSubfolders(vector<string>& folder) {
        TrieNode* root = new TrieNode();
        for (int i = 0, n = folder.size(); i < n; i++)
            insert(root, folder[i], i);

        vector<int> subfoldersRemoved;
        queue<TrieNode*> bfsQ({root});
        while (!bfsQ.empty()) {
            TrieNode* cur = bfsQ.front();
            bfsQ.pop();

            for (int i = 0; i < 26; i++)
                if (cur->child[i]) {
                    bfsQ.push(cur->child[i]);
                }

            if (cur->child[26]) {
                if (cur->child[26]->wordIndex != -1) {
                    subfoldersRemoved.push_back(cur->child[26]->wordIndex);
                } else {
                    bfsQ.push(cur->child[26]);
                }
            }
        }

        vector<string> retVal;
        for (int i : subfoldersRemoved)
            retVal.push_back(folder[i]);
        return retVal;
    }
};

int main() {
    vector<vector<string>> testCases = {
        {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"},
        {"/a", "/a/b/c", "/a/b/d"},
        {"/a/b/c", "/a/b/ca", "/a/b/d"},
    };
    for (auto& t : testCases) {
        printVector(Solution().removeSubfolders(t));
    }
    return 0;
}
