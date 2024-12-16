#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

typedef tuple<vector<int>, int, int> tc_type;

bool indexComparator(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second;
}

class Solution {
   public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int N = nums.size();
        vector<pair<int, int>> indexedNum(N);
        for (int i = 0; i < N; i++)
            indexedNum[i] = {nums[i], i};
        sort(indexedNum.begin(), indexedNum.end());

        for (int i = 0; i < k; i++) {
            indexedNum[0] = {indexedNum[0].first * multiplier, indexedNum[0].second};
            sort(indexedNum.begin(), indexedNum.end());
        }
        sort(indexedNum.begin(), indexedNum.end(), indexComparator);

        vector<int> finalStateVec(N);
        for (int i = 0; i < N; i++)
            finalStateVec[i] = indexedNum[i].first;
        return finalStateVec;
    }
};

int main() {
    vector<tc_type> testCases = {
        {{2, 1, 3, 5, 6}, 5, 2},
        {{1, 2}, 3, 4},
    };
    for (auto& t : testCases)
        printVector(Solution().getFinalState(get<0>(t), get<1>(t), get<2>(t)));

    return 0;
}
