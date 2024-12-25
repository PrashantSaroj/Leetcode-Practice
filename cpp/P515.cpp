#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
#include "utils/TreeNode.cpp"
using namespace std;

class Solution {
   public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};

        queue<pair<TreeNode*, int>> bfsQ({{root, 0}});
        vector<int> levelsVec;
        while (!bfsQ.empty()) {
            auto& [node, level] = bfsQ.front();
            bfsQ.pop();

            if (levelsVec.size() == level)
                levelsVec.push_back(node->val);
            else
                levelsVec[level] = max(levelsVec[level], node->val);

            if (node->left) bfsQ.push({node->left, level + 1});
            if (node->right) bfsQ.push({node->right, level + 1});
        }
        return levelsVec;
    }
};

int main() {
    TreeNode* root = getSampleRoot();

    printVector(Solution().largestValues(root));
    return 0;
}
