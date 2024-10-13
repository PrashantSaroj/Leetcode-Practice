#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f;

struct Pointer {
    int val, index, arrId;
};

struct Range {
    int l, r;

    bool operator<(const Range &range) const {
        int width1 = r - l;
        int width2 = range.r - range.l;
        return width1 == width2 ? l < range.l : width1 < width2;
    }
};

class ValComparator {
   public:
    int operator()(const Pointer &p1, const Pointer &p2) {
        return p1.val > p2.val;
    }
};

class Solution {
   public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        int K = nums.size();
        priority_queue<Pointer, vector<Pointer>, ValComparator> minTracker;

        int maxR = -INF;
        for (int i = 0; i < K; i++) {
            minTracker.push({nums[i][0], 0, i});
            maxR = max(maxR, nums[i][0]);
        }

        Range optRange = {0, 0x3f3f3f3f};
        while (1) {
            Pointer curMin = minTracker.top();
            minTracker.pop();

            Range curRange = {curMin.val, maxR};
            if (curRange < optRange) {
                optRange = curRange;
            }

            if (curMin.index == nums[curMin.arrId].size() - 1)
                break;

            maxR = max(maxR, nums[curMin.arrId][curMin.index + 1]);
            minTracker.push({nums[curMin.arrId][curMin.index + 1], curMin.index + 1, curMin.arrId});
        }

        return vector<int>{optRange.l, optRange.r};
    }
};

int main() {
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30},
    };

    vector<int> range = Solution().smallestRange(nums);
    cout << range[0] << " " << range[1] << endl;

    return 0;
}
