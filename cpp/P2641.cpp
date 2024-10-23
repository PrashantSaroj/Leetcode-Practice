#include <bits/stdc++.h>
#include "utils/TreeNode.cpp"
using namespace std;

class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        unordered_map<int, int> levelSum;
        queue<pair<int, TreeNode *>> bfsQ({{0, root}});
        while (!bfsQ.empty())
        {
            pair<int, TreeNode *> cur = bfsQ.front();
            bfsQ.pop();
            levelSum[cur.first] += cur.second->val;

            if (cur.second->left)
                bfsQ.push({cur.first + 1, cur.second->left});

            if (cur.second->right)
                bfsQ.push({cur.first + 1, cur.second->right});
        }

        root->val = 0;
        bfsQ.push({0, root});

        while (!bfsQ.empty())
        {
            pair<int, TreeNode *> cur = bfsQ.front();
            bfsQ.pop();
            int nephewSum = levelSum[cur.first + 1] - (cur.second->left ? cur.second->left->val : 0) - (cur.second->right ? cur.second->right->val : 0);

            if (cur.second->left)
            {
                cur.second->left->val = nephewSum;
                bfsQ.push({cur.first + 1, cur.second->left});
            }

            if (cur.second->right)
            {
                cur.second->right->val = nephewSum;
                bfsQ.push({cur.first + 1, cur.second->right});
            }
        }
        return root;
    }
};

int main()
{
    TreeNode *root = Solution().replaceValueInTree(getSampleRoot());
    printTree(root);
    return 0;
}
