#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> tc_type;

const int ALPH_SZ = 26;

class Solution {
    int findNext(int freq[], int i) {
        for (int j = i - 1; j >= 0; j--) {
            if (freq[j] > 0) return j;
        }
        return -1;
    }

   public:
    string repeatLimitedString(string s, int repeatLimit) {
        int freq[ALPH_SZ] = {};
        for (char c : s) freq[c - 'a'] += 1;

        vector<char> repeatedString;
        for (int i = ALPH_SZ - 1; i >= 0; i--) {
            while (freq[i] > 0) {
                int toAdd = min(freq[i], repeatLimit);
                freq[i] -= toAdd;
                while (toAdd--) repeatedString.push_back(i + 'a');

                if (freq[i]) {
                    int nextCharToAdd = findNext(freq, i);
                    if (nextCharToAdd == -1) {
                        break;
                    } else {
                        repeatedString.push_back(nextCharToAdd + 'a');
                        freq[nextCharToAdd]--;
                    }
                }
            }
        }
        return string(repeatedString.begin(), repeatedString.end());
    }
};

int main() {
    vector<tc_type> testCases = {
        {"cczazcc", 3},
        {"aababab", 2},
    };

    for (auto &t : testCases)
        cout << Solution().repeatLimitedString(t.first, t.second) << endl;

    return 0;
}
