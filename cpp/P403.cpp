#include <bits/stdc++.h>
using namespace std;

class Solution {
    int targetPos;
    unordered_set<int> stonesPos;
    map<pair<int, int>, int> mem;

    bool jumpHelper(int curPos, int prevJump) {
        // if reached end, true
        if (curPos == targetPos) return true;
        // if already computed return it
        pair<int, int> memoKey = {curPos, prevJump};
        if (mem.find(memoKey) != mem.end()) return mem[memoKey];

        // consider all possibilities
        bool canJump = false;
        vector<int> jumps = {prevJump - 1, prevJump, prevJump + 1};
        for (int curJump : jumps) {
            if (curJump > 0 && stonesPos.find(curPos + curJump) != stonesPos.end()) {
                canJump = jumpHelper(curPos + curJump, curJump);
                if (canJump) break;
            }
        }
        return mem[memoKey] = canJump;
    }

   public:
    bool canCross(vector<int>& stones) {
        targetPos = stones.back();
        for (int pos : stones) stonesPos.insert(pos);
        return jumpHelper(0, 0);
    }
};

int main() {
    vector<vector<int>> testCases = {
        {0, 1, 3, 5, 6, 8, 12, 17},
        {0, 1, 2, 3, 4, 8, 9, 11},
    };
    for (auto& t : testCases) cout << Solution().canCross(t) << endl;
}
