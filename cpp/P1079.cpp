#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_set<string> possibilites(string &tiles, vector<bool> &visited, int N, int depth) {
        if (depth == N) return {""};

        unordered_set<string> perm;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                unordered_set<string> child = possibilites(tiles, visited, N, depth + 1);
                for (auto &s : child) {
                    perm.insert(s);
                    perm.insert(tiles[i] + s);
                }
                visited[i] = false;
            }
        }
        return perm;
    }

   public:
    int numTilePossibilities(string &tiles) {
        int N = tiles.size();
        vector<bool> visited(N, false);
        unordered_set<string> perms = possibilites(tiles, visited, N, 0);
        perms.erase("");
        return perms.size();
    }
};

int main() {
    vector<string> testCases = {
        "AAB",
        "AAABBC",
        "V",
    };

    for (auto &t : testCases) {
        cout << Solution().numTilePossibilities(t) << endl;
    }
    return 0;
}
