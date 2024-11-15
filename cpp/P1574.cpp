#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int N = arr.size();

        int left = 0, right = N - 1;
        while (left + 1 < N && arr[left] <= arr[left + 1]) left++;
        while (right > 0 && arr[right - 1] <= arr[right]) right--;

        if (left == N - 1) return 0;

        int result = min(N - 1 - left, right);
        int i = 0, j = right;
        while (i <= left && j < N) {
            if (arr[i] <= arr[j]) {
                result = min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3, 10, 4, 2, 3, 5},
        {5, 4, 3, 2, 1},
        {1, 2, 3},
    };

    for (auto& t : testCases) {
        cout << Solution().findLengthOfShortestSubarray(t) << endl;
    }

    return 0;
}
