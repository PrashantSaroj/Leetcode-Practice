#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
    int countTwos(vector<int>& freq) {
        int count = 0;
        for (int f : freq)
            count += (f == 2);
        return count;
    }

   public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int N = A.size();
        vector<int> freq(N + 1, 0), retVal(N);
        for (int i = 0; i < N; i++) {
            freq[A[i]] += 1;
            freq[B[i]] += 1;
            retVal[i] = countTwos(freq);
        }
        return retVal;
    }
};

int main() {
    vector<pair<vector<int>, vector<int>>> testCases = {
        {{1, 3, 2, 4}, {3, 1, 2, 4}},
        {{2, 3, 1}, {3, 1, 2}},
    };

    for (auto& t : testCases)
        printVector(Solution().findThePrefixCommonArray(t.first, t.second));
    return 0;
}
