#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

typedef pair<int, int> range;
typedef pair<vector<int>, vector<vector<int>>> tc_type;

class Solution {
    int binarySearch(range query, vector<range>& specialSubArrays) {
        int l = 0, r = specialSubArrays.size() - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (query.first >= specialSubArrays[m].first && query.second <= specialSubArrays[m].second) {
                return m;
            }

            if (query.second < specialSubArrays[m].first) {
                r = m - 1;
            } else if (specialSubArrays[m].second < query.first) {
                l = m + 1;
            } else {
                return -1;
            }
        }
        return -1;
    }

   public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        int start = 0, end = 1;
        vector<range> specialSubArrays;

        while (end < N) {
            if ((nums[end] & 1) ^ (nums[end - 1] & 1)) {
                end++;
            } else {
                specialSubArrays.push_back({start, end - 1});
                start = end;
                end++;
            }
        }

        specialSubArrays.push_back({start, end - 1});

        for (auto& t : specialSubArrays) {
            cout << "(" << t.first << ", " << t.second << "), ";
        }
        cout << endl;

        // any subarray inside special subarray is special
        vector<bool> result;
        for (auto& q : queries)
            result.push_back(binarySearch({q[0], q[1]}, specialSubArrays) != -1);

        return result;
    }
};

int main() {
    vector<tc_type> testCases = {
        // {{3, 4, 1, 2, 6}, {{0, 4}}},
        // {{4, 3, 1, 6}, {{0, 2}, {2, 3}}},
        {{4, 3, 1, 6}, {{2, 3}}},
    };
    for (auto& t : testCases)
        printVector(Solution().isArraySpecial(t.first, t.second));

    return 0;
}
