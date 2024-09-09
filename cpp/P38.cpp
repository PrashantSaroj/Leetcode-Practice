#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<char> rle(vector<char> &s) {
        char curr = s[0];
        int freq = 1;
        vector<char> compressed;

        // push a dummy char for elegancy code (all done in for loop)
        s.push_back('*');

        for (int i = 1; i < s.size(); i++) {
            if (curr == s[i]) {
                freq++;
            } else {
                compressed.push_back(char(freq + '0'));
                compressed.push_back(curr);
                curr = s[i];
                freq = 1;
            }
        }
        return compressed;
    }

   public:
    string countAndSay(int n) {
        vector<char> base = {'1'};

        for (int i = 1; i < n; i++) {
            base = rle(base);
        }

        return string(base.begin(), base.end());
    }
};

int main() {
    Solution sol;
    cout << sol.countAndSay(4) << endl;

    return 0;
}
