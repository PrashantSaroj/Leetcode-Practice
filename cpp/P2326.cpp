#include <bits/stdc++.h>

#include "utils/ListNode.cpp"
#include "utils/PrintVector.cpp"
using namespace std;

typedef pair<int, int> coord;

class Solution {
    map<int, coord> dirMap = {
        {0, {0, 1}},
        {1, {1, 0}},
        {2, {0, -1}},
        {3, {-1, 0}}};

    ListNode* createDirCircularList() {
        ListNode* head = new ListNode(0);
        head->next = new ListNode(1, new ListNode(2, new ListNode(3, head)));
        return head;
    }

    ListNode* createStepsCircularList(int m, int n) {
        ListNode* head = new ListNode(n);
        head->next = new ListNode(m, head);
        return head;
    }

   public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1));
        coord curr = {0, 0};

        ListNode* dirList = createDirCircularList();
        ListNode* stepList = createStepsCircularList(m, n);
        int currSteps = stepList->val;
        coord currDir = dirMap[dirList->val];

        while (head) {
            mat[curr.first][curr.second] = head->val;

            currSteps--;
            if (currSteps == 0) {
                // change directions and make turn
                dirList = dirList->next;
                currDir = dirMap[dirList->val];

                stepList = stepList->next;
                currSteps = --stepList->val;
            }
            head = head->next;
            curr.first += currDir.first;
            curr.second += currDir.second;
        }
        return mat;
    }
};

int main() {
    ListNode* head = constructList({8, 24, 5, 21, 10, 11, 11, 12, 6, 17});
    Solution sol;

    vector<vector<int>> mat = sol.spiralMatrix(3, 5, head);
    printVecOfVector(mat);

    return 0;
}
