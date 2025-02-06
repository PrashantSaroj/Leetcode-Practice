#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> allProd;
        for (int i = 0, N = nums.size(); i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                allProd[nums[i] * nums[j]]++;
            }
        }

        int totalWays = 0;
        for (auto& [prod, ways] : allProd) {
            totalWays += ways * (ways - 1) * 4;
        }
        return totalWays;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {2, 3, 4, 6},
        {1, 2, 4, 5, 10},
    };

    for (auto& t : testCases)
        cout << Solution().tupleSameProduct(t) << endl;
    return 0;
}
