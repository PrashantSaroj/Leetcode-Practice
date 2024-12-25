#include <bits/stdc++.h>
using namespace std;

class Solution {
    inline bool inRange(int n1, int n2) {
        return 0 <= abs(n1 - n2) && abs(n1 - n2) <= 2;
    }

    bool entersInWindow(int n, map<int, int>& win) {
        if (!win.size()) {
            win[n] = 1;
            return true;
        }

        int winMin = win.begin()->first;
        int winMax = win.rbegin()->first;
        if (inRange(n, winMin) && inRange(n, winMax)) {
            win[n] += 1;
            return true;
        }
        return false;
    }

    void removeWindow(int n, map<int, int>& win) {
        if (win[n] > 1) {
            win[n] -= 1;
        } else {
            win.erase(n);
        }
    }

   public:
    long long continuousSubarrays(vector<int>& nums) {
        int N = nums.size(), w_s = 0, w_e = 0;
        long long count = 0;

        map<int, int> window;
        window[nums[0]] = 1;
        while (w_s < N) {
            if (w_e + 1 < N && entersInWindow(nums[w_e + 1], window)) {
                w_e++;
            } else {
                count += (w_e - w_s + 1);
                removeWindow(nums[w_s], window);
                w_s++;
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {5, 4, 2, 4},
        {1, 2, 3},
    };

    for (auto& t : testCases)
        cout << Solution().continuousSubarrays(t) << endl;
    return 0;
}
