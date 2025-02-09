#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long nChoose2(long long n) {
        return (n * (n - 1)) >> 1;
    }

   public:
    long long countBadPairs(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> bucket;
        for (int i = 0; i < N; i++)
            bucket[nums[i] - i]++;

        long long goodPairs = 0;
        for (auto& [key, count] : bucket)
            goodPairs += nChoose2(count);

        return nChoose2(N) - goodPairs;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {4, 1, 3, 3},
        {1, 2, 3, 4, 5},
    };

    for (auto& t : testCases)
        cout << Solution().countBadPairs(t) << endl;
    return 0;
}
