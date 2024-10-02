#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> arrayRankTransform(vector<int>& inputArr) {
        int n = inputArr.size();
        if (n == 0) {
            return {};
        }

        vector<int> arr(inputArr.begin(), inputArr.end());
        sort(arr.begin(), arr.end());
        unordered_map<int, int> rankMap;
        rankMap[arr[0]] = 1;

        int curRank = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] < arr[i]) {
                curRank++;
            }
            rankMap[arr[i]] = curRank;
        }

        vector<int> ranks;
        for (int i = 0; i < n; i++) {
            ranks.push_back(rankMap[inputArr[i]]);
        }
        return ranks;
    }
};

int main() {
    return 0;
}
