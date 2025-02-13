#include <bits/stdc++.h>
using namespace std;

class Solution {
    inline long extractMin(priority_queue<long, vector<long>, greater<long>>& heap) {
        long retVal = heap.top();
        heap.pop();
        return retVal;
    }

   public:
    int minOperations(vector<int>& nums, int k) {
        int operations = 0;
        priority_queue<long, vector<long>, greater<long>> minHeap(nums.begin(), nums.end());
        long curMin = extractMin(minHeap);

        while (curMin < k) {
            long nextMin = extractMin(minHeap);
            minHeap.push(2 * curMin + nextMin);
            curMin = extractMin(minHeap);
            operations++;
        }
        return operations;
    }
};

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{2, 11, 10, 1, 3}, 10},
        {{1, 1, 2, 4, 9}, 20}};

    for (auto& t : testCases)
        cout << Solution().minOperations(t.first, t.second) << endl;
    return 0;
}
