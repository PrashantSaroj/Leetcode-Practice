#include <bits/stdc++.h>

#include "utils/ListNode.cpp"
using namespace std;

class Solution {
    ListNode* reverseOneGroup(ListNode** head, int k) {
        // returns the end of the list
        ListNode *prev = *head, *curr = (*head)->next;
        ListNode* temp;
        while (--k) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // store the "new" last element
        ListNode* retVal = *head;

        (*head)->next = curr;
        *head = prev;
        return retVal;
    }

   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = getLength(head), subLists = n / k;
        ListNode* it = nullptr;
        while (subLists--) {
            if (it) {
                it = reverseOneGroup(&(it->next), k);
            } else {
                it = reverseOneGroup(&head, k);
            }
        }
        return head;
    }
};

int main() {
    ListNode* head = constructList({1, 2, 3, 4, 5, 6, 7, 8, 9});
    Solution sol;

    head = sol.reverseKGroup(head, 3);
    printList(head);

    return 0;
}
