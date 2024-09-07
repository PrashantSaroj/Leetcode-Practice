#include <bits/stdc++.h>

#include "utils/UnionFind.cpp"
using namespace std;

#define point pair<int, int>

class Solution {
   public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> setX, setY;
        UnionFind<point> unionFind;

        for (int i = 0; i < stones.size(); i++) {
            int x = stones[i][0], y = stones[i][1];
            bool xInSet = setX.count(x), yInSet = setY.count(y);

            point currPoint = point(x, y);
            unionFind.insert(currPoint);

            if (xInSet and yInSet) {
                point p1 = point(x, setX[x][0]);
                point p2 = point(setY[y][0], y);
                unionFind.merge(p1, p2);
                unionFind.merge(currPoint, p1);
            } else if (xInSet and !yInSet) {
                setY[y] = {x};
                unionFind.merge(currPoint, point(x, setX[x][0]));
            } else if (!xInSet and yInSet) {
                setX[x] = {y};
                unionFind.merge(currPoint, point(setY[y][0], y));
            } else {
                setX[x] = {y};
                setY[y] = {x};
            }
        }

        return stones.size() - unionFind.countDisjointSets();
    }
};

int main() {
    vector<vector<int>> stones1 = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    vector<vector<int>> stones2 = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
    Solution sol;
    cout << sol.removeStones(stones1) << endl;
    cout << sol.removeStones(stones2) << endl;
}
