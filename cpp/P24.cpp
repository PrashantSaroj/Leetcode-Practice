#include <bits/stdc++.h>

#include "utils/ListNode.cpp"
using namespace std;

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **it = &head, *p1, *p2;
        while (*it && (*it)->next) {
            p1 = *it;
            p2 = (*it)->next;
            // swap the nodes
            p1->next = p2->next;
            p2->next = p1;
            // change value of node->next from previous iteration
            *it = p2;
            // move forward
            it = &(p1->next);
        }
        return head;
    }
};

int main() {
    ListNode* head = constructList({1, 2, 3, 4, 5});
    head = Solution().swapPairs(head);
    printList(head);

    return 0;
}
