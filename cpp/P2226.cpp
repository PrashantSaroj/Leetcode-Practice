#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool canDistribute(vector<int>& candies, long long children, int pile) {
        long long maxPiles = 0;
        for (int c : candies) maxPiles += c / pile;
        return maxPiles >= children;
    }

   public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxPile = *max_element(candies.begin(), candies.end());
        int l = 1, r = maxPile, ans = 0;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (canDistribute(candies, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<pair<vector<int>, long long>> testCases = {
        {{5, 8, 6}, 3},
        {{2, 5}, 11},
    };

    for (auto& t : testCases)
        cout << Solution().maximumCandies(t.first, t.second) << endl;
}
