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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr, *curr = nullptr;

        while (list1 && list2) {
            int currVal;
            if (list1->val < list2->val) {
                currVal = list1->val;
                list1 = list1->next;
            } else {
                currVal = list2->val;
                list2 = list2->next;
            }

            if (!head) {
                head = curr = new ListNode(currVal);
            } else {
                curr->next = new ListNode(currVal);
                curr = curr->next;
            }
        }

        while (list1) {
            if (!head) {
                head = curr = new ListNode(list1->val);
            } else {
                curr->next = new ListNode(list1->val);
                curr = curr->next;
            }
            list1 = list1->next;
        }

        while (list2) {
            if (!head) {
                head = curr = new ListNode(list2->val);
            } else {
                curr->next = new ListNode(list2->val);
                curr = curr->next;
            }
            list2 = list2->next;
        }

        return head;
    }
};

int main() {
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* head2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    Solution sol;
    ListNode* merged = sol.mergeTwoLists(head1, head2);

    while (merged) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;
    return 0;
}
