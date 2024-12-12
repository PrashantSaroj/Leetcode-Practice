#include <bits/stdc++.h>
using namespace std;

typedef pair<vector<int>, int> tc_type;

class Solution {
   public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> giftsHeap(gifts.begin(), gifts.end());
        while (k--) {
            giftsHeap.push(floor(sqrt(giftsHeap.top())));
            giftsHeap.pop();
        }

        long long remVal = 0;
        while (!giftsHeap.empty()) {
            remVal += giftsHeap.top();
            giftsHeap.pop();
        }
        return remVal;
    }
};

int main() {
    vector<tc_type> testCases = {
        {{25, 64, 9, 4, 100}, 4},
        {{1, 1, 1, 1}, 4},
    };

    for (auto& t : testCases)
        cout << Solution().pickGifts(t.first, t.second) << endl;

    return 0;
}
