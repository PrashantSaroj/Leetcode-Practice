#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
    vector<vector<char>> rotate(vector<vector<char>>& box, int rowCount, int colCount) {
        vector<vector<char>> rotatedBox(colCount, vector<char>(rowCount));
        for (int i = 0; i < rowCount; i++)
            for (int j = 0; j < colCount; j++)
                rotatedBox[j][rowCount - 1 - i] = box[i][j];
        return rotatedBox;
    }

   public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rowCount = box.size(), colCount = box[0].size();
        for (int i = 0; i < rowCount; i++) {
            int curStart = colCount - 1, stoneCount = 0;
            for (int j = colCount - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    stoneCount++;
                }

                if (box[i][j] == '*' || j == 0) {
                    while (curStart > j) {
                        if (stoneCount) {
                            box[i][curStart] = '#';
                            stoneCount--;
                        } else {
                            box[i][curStart] = '.';
                        }
                        curStart--;
                    }
                    if (j == 0 && stoneCount == 0 && box[i][j] == '#') {
                        box[i][j] = '.';
                    }
                    curStart = j - 1;
                }
            }
        }
        return rotate(box, rowCount, colCount);
    }
};

int main() {
    vector<vector<vector<char>>> testCases = {
        {{'#', '.', '#'}},
        {{'#', '.', '*', '.'}, {'#', '#', '*', '.'}},
        {{'#', '#', '*', '.', '*', '.'}, {'#', '#', '#', '*', '.', '.'}, {'#', '#', '#', '.', '#', '.'}}};

    for (auto& t : testCases)
        printVecOfVector(Solution().rotateTheBox(t));

    return 0;
}
