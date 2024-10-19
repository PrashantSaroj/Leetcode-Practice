#include <bits/stdc++.h>
using namespace std;

/**
 * better solution
 * if k < mid : find kth bit in n-1
 * if k > mid: find n-k-1 th bit in n-1 and return invers
 * if k == mid: return 1
 */
class Solution {
    string reverseInvert(string &s, int N) {
        char inverted[N];
        for (int i = 0; i < N; i++)
            inverted[i] = (s[N - i - 1] == '0' ? '1' : '0');
        return string(inverted, inverted + N);
    }

    string next(string &cur) {
        int N = cur.size();
        char nextString[2 * N + 1];
        nextString[N] = '1';

        string reverseInverted = reverseInvert(cur, N);
        for (int i = 0; i < N; i++) {
            nextString[i] = cur[i];
            nextString[i + N + 1] = reverseInverted[i];
        }
        return string(nextString, nextString + 2 * N + 1);
    }

   public:
    char findKthBit(int n, int k) {
        string nthString = "0";
        for (int i = 1; i < n; i++)
            nthString = next(nthString);
        return nthString[k - 1];
    }
};

int main() {
    cout << Solution().findKthBit(3, 1) << endl;
    cout << Solution().findKthBit(4, 11) << endl;
    return 0;
}
