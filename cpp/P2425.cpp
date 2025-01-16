#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size(), N2 = nums2.size();
        int res = 0;
        if (N2 & 1) {
            for (int x : nums1)
                res = res ^ x;
        }
        if (N1 & 1) {
            for (int x : nums2)
                res = res ^ x;
        }
        return res;
    }
};

int main() {
    vector<pair<vector<int>, vector<int>>> testCases = {
        {{2, 1, 3}, {10, 2, 5, 0}},
        {{1, 2}, {3, 4}},
    };

    for (auto& t : testCases)
        cout << Solution().xorAllNums(t.first, t.second) << endl;
    return 0;
}
