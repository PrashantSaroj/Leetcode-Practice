#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minSwaps(string s) {
        int unmatchedBraces = 0;
        for (char b : s) {
            if (b == '[') {
                unmatchedBraces++;
            } else if (unmatchedBraces) {
                unmatchedBraces--;
            }
        }
        return (unmatchedBraces + 1) / 2;
    }
};

int main() {
    return 0;
}
