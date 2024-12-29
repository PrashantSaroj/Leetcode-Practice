#include <bits/stdc++.h>
using namespace std;

typedef pair<vector<string>, string> tc_type;

int ALPHA_SZ = 26, CONST_MOD = 1000000007;

class Solution {
    int W_LEN, T_LEN;
    vector<vector<int>> freq;
    vector<vector<long>> memo;

    long numWaysMemo(vector<string>& words, string& target, int i, int j) {
        // create target[i..T_LEN] from j index in words and onwars
        if (i >= T_LEN) return 1;
        if (j >= W_LEN) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        long without = numWaysMemo(words, target, i, j + 1);
        long withCur = ((long)freq[j][target[i] - 'a'] * numWaysMemo(words, target, i + 1, j + 1)) % CONST_MOD;
        memo[i][j] = (without + withCur) % CONST_MOD;
        return memo[i][j];
    }

   public:
    int numWays(vector<string>& words, string target) {
        T_LEN = target.size();
        W_LEN = words[0].size();
        memo = vector<vector<long>>(T_LEN, vector<long>(W_LEN, -1));
        freq = vector<vector<int>>(W_LEN, vector<int>(ALPHA_SZ, 0));

        // calculate frequencies
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < W_LEN; j++)
                freq[j][words[i][j] - 'a'] += 1;
        return numWaysMemo(words, target, 0, 0);
    }
};

int main() {
    vector<tc_type> testCases = {
        {{"acca", "bbbb", "caca"}, "aba"},
        {{"abba", "baab"}, "bab"},
    };

    for (auto& t : testCases)
        cout << Solution().numWays(t.first, t.second) << endl;

    return 0;
}
