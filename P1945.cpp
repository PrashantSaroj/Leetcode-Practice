#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> testCase;

class Solution {
    int sumOfDigits(int n) {
        int digitSum = 0;
        while (n > 0) {
            digitSum += (n % 10);
            n /= 10;
        }
        return digitSum;
    }

    int transformToInt(string s) {
        int stringSum = 0;
        for (char c : s) {
            int charVal = c - 'a' + 1;
            stringSum += sumOfDigits(charVal);
        }
        return stringSum;
    }

   public:
    int getLucky(string s, int k) {
        int luckyVal = 0;
        // first transformation
        luckyVal += transformToInt(s);

        k--;
        while (k--) {
            luckyVal = sumOfDigits(luckyVal);
        }
        return luckyVal;
    }
};

int main() {
    vector<testCase> T = {
        {"iiii", 1},
        {"leetcode", 2},
        {"zbax", 2},
    };

    Solution sol;
    for (testCase &tc : T) {
        cout << sol.getLucky(tc.first, tc.second) << endl;
    }

    return 0;
}