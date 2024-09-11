#include <bits/stdc++.h>

#include "utils/ListNode.cpp"
using namespace std;

class CompareListNode {
   public:
    bool operator()(ListNode* head1, ListNode* head2) {
        return head1->val > head2->val;
    }
};

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> minHeap;
        for (ListNode* head : lists) {
            minHeap.push(head);
        }

        ListNode *newHead = new ListNode(0), *it = newHead;
        while (!minHeap.empty()) {
            ListNode* currMin = minHeap.top();
            minHeap.pop();
            it->next = new ListNode(currMin->val);

            if (currMin->next) {
                minHeap.push(currMin->next);
            }
            it = it->next;
        }

        return newHead->next;
    }
};

int main() {
    vector<vector<int>> numVecs = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode*> numLists;
    for (vector<int>& nums : numVecs) {
        numLists.push_back(constructList(nums));
    }

    ListNode* merged = Solution().mergeKLists(numLists);
    printList(merged);

    return 0;
}
