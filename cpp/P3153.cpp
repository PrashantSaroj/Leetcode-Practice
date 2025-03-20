#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long otherBucketsSum(int buckets[][10], int pos, int buc) {
        long long bucSum = 0;
        for (int i = 0; i < 10; i++) {
            if (i != buc) bucSum += buckets[pos][i];
        }
        return bucSum;
    }

   public:
    long long sumDigitDifferences(vector<int>& nums) {
        int positionBuckets[10][10] = {0};
        for (int n : nums) {
            int pos = 0;
            while (n > 0) {
                int buc = n % 10;
                positionBuckets[pos][buc]++;
                pos++;
                n /= 10;
            }
        }

        long long totalDiff = 0;
        for (int pos = 0; pos < 10; pos++) {
            for (int buc = 0; buc < 10; buc++) {
                totalDiff += positionBuckets[pos][buc] * otherBucketsSum(positionBuckets, pos, buc);
            }
        }
        return totalDiff >> 1;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {13, 23, 12},
        {10, 10, 10, 10},
    };
    for (auto& t : testCases)
        cout << Solution().sumDigitDifferences(t) << endl;
}
