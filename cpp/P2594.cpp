#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool canRepair(vector<int>& ranks, int cars, long long time) {
        int i = 0;
        while (cars > 0 && i < ranks.size()) cars -= (int)sqrt(time / ranks[i++]);
        return cars <= 0;
    }

   public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = ranks[0] * cars * cars, ans = -1;
        while (l <= r) {
            long long mid = l + ((r - l) >> 1);
            if (canRepair(ranks, cars, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{4, 2, 3, 1}, 10},
        {{5, 1, 8}, 6},
    };

    for (auto& t : testCases)
        cout << Solution().repairCars(t.first, t.second) << endl;
}
