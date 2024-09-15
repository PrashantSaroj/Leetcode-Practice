#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findTheLongestSubstring(string s) {
        /**
         * all vowels odd - 11111
         * all vowels even - 00000
         */
        vector<int> first(32, -2);
        // 00000 is valid, does not depend on first
        first[0] = -1;
        int maxLen = 0, mask = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            switch (c) {
                case 'a':
                    mask ^= 1;
                case 'e':
                    mask ^= 2;
                case 'i':
                    mask ^= 4;
                case 'o':
                    mask ^= 8;
                case 'u':
                    mask ^= 16;
            }
            int prev = first[mask];
            if (prev == -2) {
                first[mask] = i;
            } else {
                maxLen = max(maxLen, i - prev);
            }
        }
        return maxLen;
    }
};

int main() {
    string tc = "eleetminicoworoep";
    cout << Solution().findTheLongestSubstring(tc) << endl;

    return 0;
}
