#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << "->";
        head = head->next;
    }
    std::cout << std::endl;
}

ListNode* constructList(vector<int> nums) {
    ListNode *head = nullptr, *it = nullptr;
    int N = nums.size();
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            head = new ListNode(nums[i]);
            it = head;
        } else {
            it->next = new ListNode(nums[i]);
            it = it->next;
        }
    }
    return head;
}
