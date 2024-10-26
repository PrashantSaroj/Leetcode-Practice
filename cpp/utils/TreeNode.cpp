#include <bits/stdc++.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *getSampleRoot()
{
    return new TreeNode(
        5,
        new TreeNode(
            8,
            new TreeNode(2,
                         new TreeNode(4),
                         new TreeNode(6)),
            new TreeNode(1)),
        new TreeNode(
            9,
            new TreeNode(3),
            new TreeNode(7)));
}

void printTree(TreeNode *root)
{
    if (!root)
        return;

    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}
