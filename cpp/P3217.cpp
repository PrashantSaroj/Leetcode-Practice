#include <bits/stdc++.h>

#include "utils/ListNode.cpp"

using namespace std;

class Solution {
   public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        ListNode** headPtr = &head;

        while (*headPtr) {
            int currVal = (*headPtr)->val;
            if (numsSet.find(currVal) != numsSet.end()) {
                *headPtr = (*headPtr)->next;
            } else {
                headPtr = &(*headPtr)->next;
            }
        }
        return head;
    }
};

int main() {
    int T = 2;
    vector<vector<int>> testNums = {{1, 2, 3}, {1}};
    vector<ListNode*> testHeads = {
        new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))),
        new ListNode(1, new ListNode(2, new ListNode(1, new ListNode(2, new ListNode(1, new ListNode(2))))))};
    Solution sol;

    for (int i = 0; i < T; i++) {
        printList(sol.modifiedList(testNums[i], testHeads[i]));
    }

    return 0;
}
