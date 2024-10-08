#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string &s) {
    int n = s.size();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}
