#include <bits/stdc++.h>

#include "utils/TreeNode.cpp"
using namespace std;

class Solution {
    TreeNode* constructLOrder(vector<vector<TreeNode*>>& levels) {
        int numberOfLevels = levels.size();
        // reverse each odd level
        for (int i = 1; i < numberOfLevels; i += 2)
            reverse(levels[i].begin(), levels[i].end());

        // change children of each even level
        for (int i = 0; i < numberOfLevels - 1; i++) {
            int levelSize = levels[i].size();
            for (int j = 0; j < levelSize; j++) {
                levels[i][j]->left = levels[i + 1][2 * j];
                levels[i][j]->right = levels[i + 1][2 * j + 1];
            }
        }

        return levels[0][0];
    }

   public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<pair<TreeNode*, int>> bfsQ({{root, 0}});
        vector<vector<TreeNode*>> levels;
        while (!bfsQ.empty()) {
            auto cur = bfsQ.front();
            bfsQ.pop();
            if (cur.second == levels.size()) levels.push_back({});

            levels[cur.second].push_back(cur.first);
            if (cur.first->left) {
                bfsQ.push({cur.first->left, cur.second + 1});
                bfsQ.push({cur.first->right, cur.second + 1});
            }
        }

        return constructLOrder(levels);
    }
};

int main() {
    TreeNode* root = getSampleRoot();
    printTree(Solution().reverseOddLevels(root));

    return 0;
}
