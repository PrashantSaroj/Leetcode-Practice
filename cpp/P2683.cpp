#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool doesValidArrayExist(vector<int>& derived, int a0) {
        int N = derived.size();

        vector<int> original(N);
        original[0] = a0;
        for (int i = 1; i < N; i++)
            original[i] = derived[i - 1] ^ original[i - 1];
        return original[N - 1] ^ original[0] == derived[N - 1];
    }

   public:
    bool doesValidArrayExist(vector<int>& derived) {
        return doesValidArrayExist(derived, 0) || doesValidArrayExist(derived, 1);
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 1, 0},
        {1, 1},
        {1, 0},
    };

    for (auto& t : testCases)
        cout << Solution().doesValidArrayExist(t) << endl;
    return 0;
}
