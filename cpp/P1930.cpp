#include <bits/stdc++.h>
using namespace std;

const int ALPHA_SZ = 26;

class Solution {
    int countUnique(string& s, int l, int r) {
        vector<int> hashMap(ALPHA_SZ, 0);
        for (int i = l + 1; i < r; i++)
            hashMap[s[i] - 'a'] = 1;
        return accumulate(hashMap.begin(), hashMap.end(), 0);
    }

   public:
    int countPalindromicSubsequence(string& s) {
        int N = s.size();
        vector<pair<int, int>> minMaxIndices(ALPHA_SZ, {INT_MAX, INT_MIN});

        for (int i = 0; i < N; i++) {
            minMaxIndices[s[i] - 'a'] = {
                min(minMaxIndices[s[i] - 'a'].first, i),
                max(minMaxIndices[s[i] - 'a'].second, i)};
        }

        int totalPals = 0;
        for (auto& c : minMaxIndices)
            totalPals += countUnique(s, c.first, c.second);

        return totalPals;
    }
};

int main() {
    vector<string> testCases = {
        "aabca",
        "adc",
        "bbcbaba",
    };

    for (auto& s : testCases)
        cout << Solution().countPalindromicSubsequence(s) << endl;
    return 0;
}
