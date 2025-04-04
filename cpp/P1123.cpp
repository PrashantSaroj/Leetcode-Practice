#include <bits/stdc++.h>

#include "utils/TreeNode.cpp"
using namespace std;

class Solution {
    unordered_set<int> deepestVals;

    void fillDeepestVal(TreeNode* root) {
        queue<TreeNode*> levelOrderQ;
        levelOrderQ.push(root);
        while (!levelOrderQ.empty()) {
            // if entered in loop again means previous level was not deepest
            deepestVals.clear();
            // process curr lvl
            int curLvlSz = levelOrderQ.size();
            while (curLvlSz--) {
                TreeNode* node = levelOrderQ.front();
                deepestVals.insert(node->val);
                // push non null children
                if (node->left) levelOrderQ.push(node->left);
                if (node->right) levelOrderQ.push(node->right);
                levelOrderQ.pop();
            }
        }
    }

    TreeNode* lcaHelper(TreeNode* root) {
        if (!root || (deepestVals.find(root->val) != deepestVals.end())) {
            return root;
        }

        TreeNode* lcaLeft = lcaHelper(root->left);
        TreeNode* lcaRight = lcaHelper(root->right);
        if (lcaLeft && lcaRight) return root;
        // return the non null child
        if (!lcaLeft) return lcaLeft;
        return lcaRight;
    }

   public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        fillDeepestVal(root);
        return lcaHelper(root);
    }
};

int main() {
    TreeNode* root = getSampleRoot();
    printTree(Solution().lcaDeepestLeaves(root));
}
