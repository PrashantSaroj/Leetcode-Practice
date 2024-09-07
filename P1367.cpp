#include <bits/stdc++.h>

#include "utils/ListNode.cpp"
#include "utils/TreeNode.cpp"

using namespace std;

class Solution {
    ListNode* originalHead;
    map<pair<ListNode*, TreeNode*>, bool> memo;

    bool helper(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root) {
            // elements in list remains but tree has ended
            return false;
        }

        pair<ListNode*, TreeNode*> memoKey = {head, root};
        if (memo.find(memoKey) != memo.end()) {
            return memo[memoKey];
        }

        bool consumable = false;

        if (head->val == root->val) {
            consumable = helper(head->next, root->left) || helper(head->next, root->right);
        }
        memo[memoKey] = consumable || helper(originalHead, root->left) || helper(originalHead, root->right);
        return memo[memoKey];
    }

   public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        originalHead = head;
        return helper(head, root);
    }
};

int main() {
    TreeNode* root = getSampleRoot();
    ListNode* head = new ListNode(4, new ListNode(2, new ListNode(8)));

    cout << Solution().isSubPath(head, root) << endl;

    return 0;
}
