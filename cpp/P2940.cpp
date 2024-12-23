#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

typedef pair<vector<int>, vector<vector<int>>> tc_type;

class Solution {
   public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<pair<int, int>> monoStack;
        vector<int> result(queries.size(), -1);
        vector<vector<pair<int, int>>> newQueries(heights.size());
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) swap(a, b);
            if (heights[b] > heights[a] || a == b)
                result[i] = b;
            else
                newQueries[b].push_back({heights[a], i});
        }

        for (int i = heights.size() - 1; i >= 0; i--) {
            int monoStackSize = monoStack.size();
            for (auto& [a, b] : newQueries[i]) {
                int position = search(a, monoStack);
                if (position < monoStackSize && position >= 0)
                    result[b] = monoStack[position].second;
            }
            while (!monoStack.empty() && monoStack.back().first <= heights[i])
                monoStack.pop_back();
            monoStack.push_back({heights[i], i});
        }
        return result;
    }

   private:
    int search(int height, vector<pair<int, int>>& monoStack) {
        int left = 0;
        int right = monoStack.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (monoStack[mid].first > height) {
                ans = max(ans, mid);
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return ans;
    }
};

int main() {
    vector<tc_type> testCases = {
        {{6, 4, 8, 5, 2, 7}, {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}}},
        {{5, 3, 8, 2, 6, 1, 4, 6}, {{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}}},
    };

    for (auto& t : testCases)
        printVector(Solution().leftmostBuildingQueries(t.first, t.second));
    return 0;
}
