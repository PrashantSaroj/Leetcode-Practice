#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int BS = 9;
    const int SS = 3;

    bool checkCell(char c, vector<bool>& mask) {
        if (c != '.') {
            if (mask[c - '1']) {
                return false;
            }
            mask[c - '1'] = true;
        }
        return true;
    }

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for (int i = 0; i < BS; i++) {
            vector<bool> freq(BS, 0);
            for (int j = 0; j < BS; j++) {
                char curr = board[i][j];
                if (!checkCell(curr, freq)) {
                    return false;
                }
            }
        }
        // check columns
        for (int j = 0; j < BS; j++) {
            vector<bool> freq(BS, 0);
            for (int i = 0; i < BS; i++) {
                char curr = board[i][j];
                if (!checkCell(curr, freq)) {
                    return false;
                }
            }
        }

        // check sub-boxes
        for (int rowM = 0; rowM < SS; rowM++) {
            for (int colM = 0; colM < SS; colM++) {
                vector<bool> freq(BS, 0);
                for (int i = 0; i < SS; i++) {
                    for (int j = 0; j < SS; j++) {
                        int rowIndex = rowM * SS + i;
                        int colIndex = colM * SS + j;
                        char curr = board[rowIndex][colIndex];
                        if (!checkCell(curr, freq)) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution sol;

    cout << sol.isValidSudoku(board) << endl;
    return 0;
}
