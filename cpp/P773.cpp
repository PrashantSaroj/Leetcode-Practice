#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Board {
   public:
    vector<vector<int>> mat;
    int rowCount = 2, colCount = 3;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    pair<int, int> findZero() {
        for (int i = 0; i < rowCount; i++)
            for (int j = 0; j < colCount; j++)
                if (mat[i][j] == 0) return {i, j};
        return {-1, -1};
    }

    Board(vector<vector<int>>& board) { mat = board; }

    vector<Board> makeMove() {
        vector<Board> moves;
        pair<int, int> zeroPos = findZero();

        for (auto& dir : dirs) {
            int i = zeroPos.first + dir.first;
            int j = zeroPos.second + dir.second;
            if (rowCount > i && i >= 0 && colCount > j && j >= 0) {
                vector<vector<int>> matNew = mat;
                matNew[i][j] = 0;
                matNew[zeroPos.first][zeroPos.second] = mat[i][j];
                moves.push_back(Board(matNew));
            }
        }
        return moves;
    }

    bool operator==(Board const& obj) {
        return mat == obj.mat;
    }
};

struct BoardCompare {
    bool operator()(const Board& lhs, const Board& rhs) const {
        return lhs.mat < rhs.mat;
    }
};

class Solution {
    map<Board, int, BoardCompare> movesMap;
    vector<vector<int>> startBoard = {{1, 2, 3}, {4, 5, 0}};

   public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<pair<Board, int>> bfsQ({{Board(startBoard), 0}});
        while (!bfsQ.empty()) {
            auto curNode = bfsQ.front();
            movesMap[curNode.first] = curNode.second;
            auto nextMoves = curNode.first.makeMove();
            for (auto& move : nextMoves) {
                if (movesMap.find(move) == movesMap.end()) {
                    bfsQ.push({move, curNode.second + 1});
                }
            }
            bfsQ.pop();
        }

        return movesMap.find(board) != movesMap.end() ? movesMap[board] : -1;
    }
};

int main() {
    vector<vector<vector<int>>> testCases = {
        {{1, 2, 3}, {4, 0, 5}},
        {{1, 2, 3}, {5, 4, 0}},
        {{4, 1, 2}, {5, 0, 3}},
    };

    for (auto& t : testCases)
        cout << Solution().slidingPuzzle(t) << endl;

    return 0;
}
