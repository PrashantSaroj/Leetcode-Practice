#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numberOfSubstrings(string& s) {
        int N = s.size();
        int nextPos[N][3];
        int next[3] = {N, N, N};
        for (int i = N - 1; i >= 0; i--) {
            next[s[i] - 'a'] = i;
            for (int j = 0; j < 3; j++) nextPos[i][j] = next[j];
        }

        int totalBeautiful = 0;
        for (int i = 0; i < N; i++) {
            int smallestBeautiful = INT_MIN;
            for (int j = 0; j < 3; j++)
                smallestBeautiful = max(smallestBeautiful, nextPos[i][j]);
            totalBeautiful += (N - smallestBeautiful);
        }
        return totalBeautiful;
    }
};

int main() {
    vector<string> testCases = {
        "abcabc",
        "aaacb",
        "abc",
    };

    for (auto& t : testCases)
        cout << Solution().numberOfSubstrings(t) << endl;
    return 0;
}
