#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

#define INF 0x3f3f3f3f

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int lastUniqeIndex = 0;
        // mark dupicates as -1
        for (int i = 1; i < nums.size(); i++) {
            if (nums[lastUniqeIndex] == nums[i]) {
                nums[i] = INF;
            } else {
                lastUniqeIndex = i;
            }
        }

        // move all the INF(s) to end
        int lastINFIndex = 0;
        while (lastINFIndex < nums.size()) {
            if (nums[lastINFIndex] == INF) {
                break;
            }
            lastINFIndex++;
        }

        for (int i = lastINFIndex; i < nums.size(); i++) {
            if (nums[i] != INF) {
                nums[lastINFIndex] = nums[i];
                nums[i] = INF;
                lastINFIndex += 1;
            }
        }

        return lastINFIndex;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 1, 2},
        {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}};
    Solution sol;

    for (vector<int>& t : testCases) {
        cout << sol.removeDuplicates(t) << endl;
        printVector(t);
    }
    return 0;
}
