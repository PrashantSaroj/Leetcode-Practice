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
        4,
        new TreeNode(
            4,
            nullptr,
            new TreeNode(
                2,
                new TreeNode(1),
                nullptr)),
        new TreeNode(
            4,
            new TreeNode(
                2,
                new TreeNode(6),
                new TreeNode(
                    8,
                    new TreeNode(1),
                    new TreeNode(3))),
            nullptr));
}
