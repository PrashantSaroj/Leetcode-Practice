#include <bits/stdc++.h>

#include "utils/TreeNode.cpp"
using namespace std;

class Solution {
    map<pair<long, bool>, int> memo;

    int robHelper(TreeNode* root, bool canTake) {
        if (!root) return 0;
        pair<long, bool> memoKey = {(long)root, canTake};
        if (memo.find(memoKey) != memo.end()) return memo[memoKey];

        if (!canTake) {
            return memo[memoKey] = robHelper(root->left, true) + robHelper(root->right, true);
        }
        return memo[memoKey] = max(
                   root->val + robHelper(root->left, false) + robHelper(root->right, false),
                   robHelper(root->left, true) + robHelper(root->right, false));
    }

   public:
    int rob(TreeNode* root) {
        return max(robHelper(root, true), robHelper(root, false));
    }
};

int main() {
    TreeNode* root = getSampleRoot();
    cout << Solution().rob(root) << endl;
}
