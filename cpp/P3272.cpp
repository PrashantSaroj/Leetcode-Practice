#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_set<string> palSet;

    int numCombinations(const string &s) {
        int f[10] = {0};
        for (char c : s) f[c - '0']++;
        int comb = (s.size() - f[0]) * qFac[s.size() - 1];
        for (int i = 0; i < 10; i++) {
            if (f[i] > 1) comb /= qFac[f[i]];
        }
        return comb;
    }

    int pow10[6] = {1, 10, 100, 1000, 10000, 100000};
    int qFac[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

   public:
    long long countGoodIntegers(int n, int k) {
        int start = pow10[(n - 1) >> 1];
        /* Enumerate the number of palindrome numbers of n digits */
        for (int i = start; i < start * 10; i++) {
            string s = to_string(i);
            s += string(s.rbegin() + (n & 1), s.rend());
            long long palindrome = stoll(s);
            /* If the current palindrome number is a k-palindromic integer */
            if (palindrome && palindrome % k == 0) {
                sort(s.begin(), s.end());
                palSet.emplace(s);
            }
        }

        long long goodCount = 0;
        for (const string &s : palSet) goodCount += numCombinations(s);
        return goodCount;
    }
};

int main() {
    vector<pair<int, int>> testCases = {
        {2, 1},
        {3, 5},
        {1, 4},
        {5, 6},
    };
    for (auto &t : testCases) {
        cout << Solution().countGoodIntegers(t.first, t.second) << endl;
    }
}
