#include <bits/stdc++.h>
using namespace std;

const int ALPHA_SZ = 26;
class Solution {
    vector<int> calcFreq(string& s) {
        vector<int> freq(ALPHA_SZ, 0);
        for (char c : s)
            freq[c - 'a'] += 1;
        return freq;
    }

    int oddCount(vector<int>& s) {
        int count = 0;
        for (int i = 0; i < ALPHA_SZ; i++)
            count += (s[i] & 1);
        return count;
    }

   public:
    bool canConstruct(string& s, int k) {
        if (s.size() < k) return false;
        vector<int> freq = calcFreq(s);
        return oddCount(freq) <= k;
    }
};

int main() {
    vector<pair<string, int>> testCases = {
        {"annabelle", 2},
        {"leetcode", 3},
        {"true", 4},
    };

    for (auto& t : testCases)
        cout << Solution().canConstruct(t.first, t.second) << endl;
    return 0;
}
