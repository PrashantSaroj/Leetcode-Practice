#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
   public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderFreq(k, 0);
        for (int n : arr) {
            int rem = (n % k + k) % k;
            remainderFreq[rem]++;
        }

        // family-0 and k/2 combine with itself, must be even
        if (remainderFreq[0] & 1) {
            return false;
        }
        if (!(k & 1) and (remainderFreq[k / 2] & 1)) {
            return false;
        }
        for (int i = 1, mid = k / 2; i <= mid; i++) {
            if (remainderFreq[i] != remainderFreq[k - i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {3, 8, 7, 2},
        {1, 2, 3, 4, 5, 10, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6}};
    vector<int> kValues = {10, 5, 10};
    for (int i = 0; i < kValues.size(); i++) {
        cout << Solution().canArrange(testCases[i], kValues[i]) << endl;
    }
    return 0;
}
