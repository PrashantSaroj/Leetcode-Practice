#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long maxRunSum = 0, minRunSum = 0, runSum = 0;
        for (int n : differences) {
            runSum += n;
            maxRunSum = max(maxRunSum, runSum);
            minRunSum = min(minRunSum, runSum);
        }
        long minFirst = lower - minRunSum;
        long maxFirst = upper - maxRunSum;
        return max(0L, maxFirst - minFirst + 1);
    }
};

typedef tuple<vector<int>, int, int> tc_type;
int main() {
    vector<tc_type> testCases = {
        {{1, -3, 4}, 1, 6},
        {{3, -4, 5, 1, -2}, -4, 5},
        {{4, -7, 2}, 3, 6},
    };
    for (auto& t : testCases) {
        printf("#Arrays: %i\n", Solution().numberOfArrays(get<0>(t), get<1>(t), get<2>(t)));
    }
}
