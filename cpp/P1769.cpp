#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
    inline int countOnesRight(string& s, int size) {
        int count = 0;
        for (int i = 1; i < size; i++)
            count += (s[i] == '1');
        return count;
    }

    inline int computeCost(string& s, int size) {
        int cost = 0;
        for (int i = 1; i < size; i++)
            cost += (s[i] == '1' ? i : 0);
        return cost;
    }

   public:
    vector<int> minOperations(string& boxes) {
        int numBoxes = boxes.size();
        pair<int, int> leftRight[numBoxes];
        leftRight[0] = {0, countOnesRight(boxes, numBoxes)};
        for (int i = 1; i < numBoxes; i++)
            leftRight[i] = {
                leftRight[i - 1].first + (boxes[i - 1] == '1'),
                leftRight[i - 1].second - (boxes[i] == '1')};

        vector<int> costs(numBoxes);
        costs[0] = computeCost(boxes, numBoxes);
        for (int i = 1; i < numBoxes; i++) {
            auto& [l, r] = leftRight[i - 1];
            costs[i] = costs[i - 1] + l - r + (boxes[i - 1] == '1');
        }
        return costs;
    }
};

int main() {
    vector<string> testCases = {
        "110",
        "001011",
    };

    for (auto& t : testCases)
        printVector(Solution().minOperations(t));
    return 0;
}
