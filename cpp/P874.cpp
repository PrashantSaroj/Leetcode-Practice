#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector<int> rotateLeft(vector<int>& dVec) {
        return {-dVec[1], dVec[0]};
    }

    vector<int> rotateRight(vector<int>& dVec) {
        return {dVec[1], -dVec[0]};
    }

   public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> currDir = {0, 1}, currPoint = {0, 0};
        set<vector<int>> obsSet(obstacles.begin(), obstacles.end());
        int farthestDist = 0;

        for (int com : commands) {
            switch (com) {
                case -2:
                    currDir = rotateLeft(currDir);
                    break;
                case -1:
                    currDir = rotateRight(currDir);
                    break;
                default:
                    while (com--) {
                        vector<int> newPoint = {currPoint[0] + currDir[0], currPoint[1] + currDir[1]};
                        if (obsSet.find(newPoint) != obsSet.end()) {
                            break;
                        }
                        currPoint = newPoint;
                    }
                    int currDistance = currPoint[0] * currPoint[0] + currPoint[1] * currPoint[1];
                    farthestDist = max(currDistance, farthestDist);
                    break;
            }
        }
        return farthestDist;
    }
};

int main() {
    int testCases = 3;
    vector<vector<int>> testCommands = {{4, -1, 3}, {4, -1, 4, -2, 4}, {6, -1, -1, 6}};
    vector<vector<vector<int>>> testObstacles = {{{}}, {{2, 4}}, {{}}};

    Solution sol;
    while (testCases--) {
        cout << sol.robotSim(testCommands[testCases], testObstacles[testCases]) << endl;
    }

    return 0;
}
