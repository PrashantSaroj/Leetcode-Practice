#include <bits/stdc++.h>

#include "utils/TreeNode.cpp"
using namespace std;

class Solution {
    void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int minSwaps(vector<int>& arr, int N) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        map<int, int> h;
        for (int i = 0; i < N; i++)
            h[arr[i]] = i;

        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] != temp[i]) {
                ans++;
                int init = arr[i];
                swap(arr, i, h[temp[i]]);

                h[init] = h[temp[i]];
                h[temp[i]] = i;
            }
        }
        return ans;
    }

   public:
    int minimumOperations(TreeNode* root) {
        vector<vector<int>> levelsVec;

        queue<pair<TreeNode*, int>> bfsQ({{root, 0}});
        while (!bfsQ.empty()) {
            auto& [node, level] = bfsQ.front();
            bfsQ.pop();
            if (levelsVec.size() == level) {
                levelsVec.push_back({node->val});
            } else {
                levelsVec[level].push_back(node->val);
            }

            if (node->left) bfsQ.push({node->left, level + 1});
            if (node->right) bfsQ.push({node->right, level + 1});
        }

        int totalSwaps = 0;
        for (auto& level : levelsVec)
            totalSwaps += minSwaps(level, level.size());
        return totalSwaps;
    }
};

int main() {
    TreeNode* root = getSampleRoot();

    cout << Solution().minimumOperations(root) << endl;
    return 0;
}
