#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *getSampleRoot() {
    return new TreeNode(
        2,
        new TreeNode(
            3,
            new TreeNode(8),
            new TreeNode(13)),
        new TreeNode(
            5,
            new TreeNode(21),
            new TreeNode(34)));
}

void printTree(TreeNode *root) {
    if (!root)
        return;

    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}
