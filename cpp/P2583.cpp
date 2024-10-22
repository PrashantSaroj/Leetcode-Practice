#include <bits/stdc++.h>
#include "utils/TreeNode.cpp"
using namespace std;

class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        map<int, long long> levelSums;
        queue<pair<TreeNode *, int>> bfsQueue;
        bfsQueue.push({root, 0});

        while (!bfsQueue.empty())
        {
            auto cur = bfsQueue.front();
            bfsQueue.pop();

            levelSums[cur.second] += (cur.first)->val;

            if (cur.first->left)
                bfsQueue.push({cur.first->left, cur.second + 1});
            if (cur.first->right)
                bfsQueue.push({cur.first->right, cur.second + 1});
        }

        if (levelSums.size() < k)
            return -1;

        vector<long long> sortedSums(levelSums.size());
        for (auto it : levelSums)
            sortedSums[it.first] = it.second;
        sort(sortedSums.begin(), sortedSums.end(), greater<long long>());
        return sortedSums[k - 1];
    }
};

int main()
{
    cout << Solution().kthLargestLevelSum(getSampleRoot(), 2) << endl;
    return 0;
}
