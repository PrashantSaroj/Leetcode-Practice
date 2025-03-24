#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    Node* connect(Node* root) {
        if (!root) return root;

        queue<Node*> Q({root});
        while (!Q.empty()) {
            int levelSize = Q.size();
            for (int i = 0; i < levelSize; i++) {
                Node* curr = Q.front();
                Q.pop();
                if (i != levelSize - 1) curr->next = Q.front();

                if (curr->left) Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
            }
        }
        return root;
    }
};

int main() {
    Node* root = new Node(1, new Node(2), new Node(3), 0);
    Solution().connect(root);
    return 0;
}
