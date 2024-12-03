#include <bits/stdc++.h>
using namespace std;

typedef pair<string, vector<int>> tc_type;

class Solution {
   public:
    string addSpaces(string s, vector<int>& spaces) {
        int sSize = s.size(), spaceCount = spaces.size();
        char stringWithSpaces[sSize + spaceCount];

        int fCounter = 0, sCounter = 0;
        for (int i = 0; i < sSize; i++) {
            if (sCounter < spaceCount && i == spaces[sCounter]) {
                stringWithSpaces[fCounter++] = ' ';
                sCounter++;
            }
            stringWithSpaces[fCounter++] = s[i];
        }
        return string(stringWithSpaces, stringWithSpaces + sSize + spaceCount);
    }
};

int main() {
    vector<tc_type> testCases = {
        {"LeetcodeHelpsMeLearn", {8, 13, 15}},
        {"icodeinpython", {1, 5, 7, 9}},
        {"spacing", {0, 1, 2, 3, 4, 5, 6}},
    };
    for (auto& t : testCases) {
        cout << Solution().addSpaces(t.first, t.second) << endl;
    }
    return 0;
}
