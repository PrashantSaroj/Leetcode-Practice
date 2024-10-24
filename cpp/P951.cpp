#include <bits/stdc++.h>
#include "utils/TreeNode.cpp"
using namespace std;

class Solution
{
    inline bool nodeEqual(TreeNode *n1, TreeNode *n2)
    {
        return (!n1 && !n2) || (n1 && n2 && n1->val == n2->val);
    }

public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return true;

        if (root1 && root2 && root1->val == root2->val)
        {
            TreeNode *l1 = root1->left, *r1 = root1->right;
            TreeNode *l2 = root2->left, *r2 = root2->right;

            if (nodeEqual(l1, l2) && nodeEqual(r1, r2))
            {
                // no flip needed
                return flipEquiv(l1, l2) && flipEquiv(r1, r2);
            }

            if (nodeEqual(l1, r2) && nodeEqual(r1, l2))
            {
                // flip needed; don't actually need to swap;
                return flipEquiv(l1, r2) && flipEquiv(r1, l2);
            }

            return false;
        }
        return false;
    }
};

int main()
{
    return 0;
}
