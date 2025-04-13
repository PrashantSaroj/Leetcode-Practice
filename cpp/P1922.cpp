#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = 1e9 + 7;

    long long powMod(int base, long long exp) {
        if (!exp) return 1;
        long long halfPowMod = powMod(base, exp >> 1);
        long long fullPowMod = (halfPowMod * halfPowMod) % mod;
        if (exp & 1) fullPowMod = (fullPowMod * base) % mod;
        return fullPowMod;
    }

   public:
    int countGoodNumbers(long long n) {
        long long pow5 = (n >> 1) + (n & 1);
        long long pow4 = n >> 1;
        return (powMod(4, pow4) * powMod(5, pow5)) % mod;
    }
};

int main() {
    vector<int> testCases = {1, 4, 50};
    for (auto &t : testCases) printf("Good numbers: %i \n", Solution().countGoodNumbers(t));
}
