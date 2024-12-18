#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
   public:
    vector<int> finalPrices(vector<int>& prices) {
        int N = prices.size();
        stack<int> nextLesser;
        vector<int> discountedPrices(N);

        for (int i = N - 1; i >= 0; i--) {
            while (!nextLesser.empty() && nextLesser.top() > prices[i]) nextLesser.pop();
            discountedPrices[i] = prices[i] - (!nextLesser.empty() ? nextLesser.top() : 0);
            nextLesser.push(prices[i]);
        }
        return discountedPrices;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {8, 4, 6, 2, 3},
        {1, 2, 3, 4, 5},
        {10, 1, 1, 6},
    };

    for (auto& t : testCases)
        printVector(Solution().finalPrices(t));

    return 0;
}
