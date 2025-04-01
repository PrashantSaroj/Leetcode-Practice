#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<long long> memo;

    long long pointsHelper(vector<vector<int>>& questions, int start) {
        if (start >= questions.size()) return 0;
        if (memo[start] != -1) return memo[start];

        return memo[start] = max(
                   questions[start][0] + pointsHelper(questions, start + questions[start][1] + 1),
                   pointsHelper(questions, start + 1));
    }

   public:
    long long mostPoints(vector<vector<int>>& questions) {
        memo.resize(questions.size(), -1);
        return pointsHelper(questions, 0);
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{3, 2}, {4, 3}, {4, 4}, {2, 5}},
        {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}},
    };
    for (auto& t : testCases) cout << Solution().mostPoints(t) << endl;
}
