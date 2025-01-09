#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPrefix(string& s1, string& s2) {
        int i1 = 0, i2 = 0;
        int N1 = s1.size(), N2 = s2.size();
        while (i1 < N1 && i2 < N2) {
            if (s1[i1] != s2[i2]) return false;
            i1++;
            i2++;
        }
        return i1 == N1;
    }

   public:
    int prefixCount(vector<string>& words, string& pref) {
        int count = 0;
        for (int i = 0, N = words.size(); i < N; i++)
            count += isPrefix(pref, words[i]);
        return count;
    }
};

int main() {
    vector<pair<vector<string>, string>> testCases = {
        {{"pay", "attention", "practice", "attend"}, "at"},
        {{"leetcode", "win", "loops", "success"}, "code"},
    };

    for (auto& t : testCases)
        cout << Solution().prefixCount(t.first, t.second) << endl;
    return 0;
}
