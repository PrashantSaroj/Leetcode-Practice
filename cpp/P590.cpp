#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

template <typename T>
T peekAndPop(stack<T> &s)
{
    T top = s.top();
    s.pop();
    return top;
}

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        stack<int> printStack;
        stack<Node *> procStack;

        procStack.push(root);
        while (!procStack.empty())
        {
            Node *currTop = peekAndPop(procStack);
            if (currTop)
            {
                printStack.push(currTop->val);
                for (Node *child : currTop->children)
                {
                    procStack.push(child);
                }
            }
        }

        vector<int> postVec;
        while (!printStack.empty())
        {
            postVec.push_back(peekAndPop(printStack));
        }
        return postVec;
    }
};

int main()
{
    Node *root = new Node(1, vector<Node *>{new Node(2, vector<Node *>{new Node(4), new Node(5)}), new Node(3, vector<Node *>{new Node(6), new Node(7)})});
    Solution sol;
    vector<int> postVec = sol.postorder(root);
    for (int val : postVec)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
