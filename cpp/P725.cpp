#include <bits/stdc++.h>

#include "utils/ListNode.cpp"
using namespace std;

typedef pair<ListNode*, int> tc;

class Solution {
    int getSize(ListNode* head) {
        ListNode* it = head;
        int sz = 0;
        while (it) {
            it = it->next;
            sz++;
        }
        return sz;
    }

    ListNode* split(ListNode*& head, int size) {
        ListNode *splittedHead = nullptr, *it = nullptr;

        for (int i = 0; i < size; i++) {
            if (i == 0) {
                splittedHead = new ListNode(head->val);
                it = splittedHead;
            } else {
                it->next = new ListNode(head->val);
                it = it->next;
            }
            head = head->next;
        }
        return splittedHead;
    }

   public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = getSize(head);
        int quot = N / k, rem = N % k;
        vector<ListNode*> result;

        ListNode* it = head;
        for (int i = 0; i < k; i++) {
            int currSize = i < rem ? quot + 1 : quot;
            result.push_back(split(it, currSize));
        }
        return result;
    }
};

int main() {
    vector<tc> testCases = {
        {constructList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}), 3}};
    Solution sol;

    for (auto& t : testCases) {
        vector<ListNode*> result = sol.splitListToParts(t.first, t.second);
        for (auto r : result) {
            printList(r);
        }
    }

    return 0;
}
