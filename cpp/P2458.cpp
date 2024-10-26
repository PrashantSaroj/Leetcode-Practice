#include <bits/stdc++.h>
#include "utils/TreeNode.cpp"
#include "utils/PrintVector.cpp"

using namespace std;

struct AugmentedNode
{
    int val;
    int height;
};

bool compareByHeight(const AugmentedNode &l, const AugmentedNode &r)
{
    return l.height > r.height;
}

class Solution
{
    map<int, vector<AugmentedNode>> levelToNodes;
    map<int, int> nodeToLevel;

    void sortLevelsByHeight()
    {
        for (auto &curLevel : levelToNodes)
            sort(curLevel.second.begin(), curLevel.second.end(), compareByHeight);
    }

    int calcHeightPostOrder(TreeNode *root, int level)
    {
        if (!root)
            return 0;

        int h = 1 + max(
                        calcHeightPostOrder(root->left, level + 1),
                        calcHeightPostOrder(root->right, level + 1));

        if (levelToNodes.find(level) == levelToNodes.end())
        {
            levelToNodes[level] = {};
        }
        levelToNodes[level].push_back({root->val, h});
        nodeToLevel[root->val] = level;
        return h;
    }

public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        calcHeightPostOrder(root, 0);
        sortLevelsByHeight();

        vector<int> queriesResult;
        for (int nodeVal : queries)
        {
            int curLevel = nodeToLevel[nodeVal];

            if (levelToNodes[curLevel][0].val == nodeVal)
            {
                if (levelToNodes[curLevel].size() > 1)
                    queriesResult.push_back(levelToNodes[curLevel][1].height + curLevel - 1);
                else
                    queriesResult.push_back(curLevel - 1);
            }
            else
                queriesResult.push_back(levelToNodes[curLevel][0].height + curLevel - 1);
        }

        return queriesResult;
    }
};

int main()
{
    vector<int> queries = {3, 2, 4, 8};
    vector<int> results = Solution().treeQueries(getSampleRoot(), queries);
    printVector(results);
    return 0;
}
