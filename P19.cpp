#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode **fast = &head, **slow = &head;
        while (n--) {
            fast = &(*fast)->next;
        }

        while (*fast) {
            fast = &(*fast)->next;
            slow = &(*slow)->next;
        }

        if (*slow == head) {
            // first element to remove
            head = head->next;
        } else {
            *slow = (*slow)->next;
        }

        return head;
    }
};

int main() {
}
