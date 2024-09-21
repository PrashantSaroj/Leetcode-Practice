#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
   public:
    vector<int> lexicalOrder(int n) {
        int curr = 1;
        vector<int> lexSorted(n);

        for (int i = 0; i < n; i++) {
            lexSorted[i] = curr;
            if (curr * 10 <= n) {
                curr = curr * 10;
            } else {
                while (curr % 10 == 9 || curr >= n) {
                    curr = curr / 10;
                }
                curr += 1;
            }
        }
        return lexSorted;
    }
};

int main() {
    vector<int> lexSorted = Solution().lexicalOrder(13);
    printVector(lexSorted);

    return 0;
}
