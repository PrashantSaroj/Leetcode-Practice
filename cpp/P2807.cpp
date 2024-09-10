#include <bits/stdc++.h>

#include "utils/ListNode.cpp"
using namespace std;

class Solution {
    int gcd(int a, int b) {
        if (a % b == 0) {
            return b;
        }
        return gcd(b, a % b);
    }

   public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *it = head, *tmp;
        while (it && it->next) {
            int curGcd = gcd(it->val, it->next->val);
            tmp = it->next;
            it->next = new ListNode(curGcd, tmp);
            // move forward
            it = it->next->next;
        }
        return head;
    }
};

int main() {
    vector<ListNode*> testCases = {
        constructList({18, 6, 10, 3}),
        constructList({6})};
    Solution sol;

    for (auto head : testCases) {
        ListNode* newHead = sol.insertGreatestCommonDivisors(head);
        printList(newHead);
    }
    return 0;
}
