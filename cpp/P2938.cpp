#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long minimumSteps(string s) {
        int N = s.size(), rightmostZero = N;
        while (--rightmostZero >= 0 && s[rightmostZero] == '1');

        long long steps = 0;
        for (int i = rightmostZero - 1; i >= 0; i--) {
            if (s[i] == '1') {
                steps += (rightmostZero - i);
                rightmostZero--;
            }
        }
        return steps;
    }
};

int main() {
    vector<string> testCases = {
        "101",
        "100",
        "0111",
    };
    for (string s : testCases)
        cout << Solution().minimumSteps(s) << endl;
    return 0;
}
