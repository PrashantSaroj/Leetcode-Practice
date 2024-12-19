#include <bits/stdc++.h>
using namespace std;

class Solution {
    int calcChunks(vector<int>& arr, int N, int start) {
        unordered_set<int> elements;
        int i = start;
        for (; i < N; i++) {
            bool chunkFound = true;
            elements.insert(arr[i]);
            for (int j = start; j <= i; j++) {
                if (!elements.count(j)) {
                    chunkFound = false;
                    break;
                }
            }
            if (chunkFound) {
                return 1 + calcChunks(arr, N, i + 1);
            }
        }
        return start == N ? 0 : 1;
    }

   public:
    int maxChunksToSorted(vector<int>& arr) {
        return calcChunks(arr, arr.size(), 0);
    }
};

int main() {
    vector<vector<int>> testCases = {
        {4, 3, 2, 1, 0},
        {1, 0, 2, 3, 4},
    };

    for (auto& t : testCases)
        cout << Solution().maxChunksToSorted(t) << endl;

    return 0;
}
