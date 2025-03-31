#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long putMarbles(vector<int>& weights, int k) {
        int HEAP_SIZE = k - 1, N = weights.size();
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 1; i < N; i++) {
            int curSum = weights[i] + weights[i - 1];
            // track min elements in max heap
            maxHeap.push(curSum);
            if (maxHeap.size() > HEAP_SIZE) maxHeap.pop();
            // track max elements in min heap
            minHeap.push(curSum);
            if (minHeap.size() > HEAP_SIZE) minHeap.pop();
        }

        // first and last elements are mandatory
        long long minCost = weights[0] + weights[N - 1];
        long long maxCost = minCost;
        while (!maxHeap.empty()) {
            minCost += maxHeap.top();
            maxCost += minHeap.top();
            maxHeap.pop();
            minHeap.pop();
        }
        return maxCost - minCost;
    }
};

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{1, 3, 5, 1}, 2},
        {{1, 3}, 2},
    };

    for (auto& t : testCases) cout << Solution().putMarbles(t.first, t.second) << endl;
}
