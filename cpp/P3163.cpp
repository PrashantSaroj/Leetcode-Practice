#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string compressedString(string word) {
        vector<char> comp;
        int count = 1, cur = word[0];
        for (int i = 1, N = word.size(); i < N; i++) {
            if (word[i] != cur || count == 9) {
                comp.push_back(count + '0');
                comp.push_back(cur);
                // update counters
                cur = word[i];
                count = 0;
            }
            count++;
        }
        comp.push_back(count + '0');
        comp.push_back(cur);
        return string(comp.begin(), comp.end());
    }
};

int main() {
    vector<string> testCases = {
        "abcde",
        "aaaaaaaaaaaaaabb",
    };

    for (string &s : testCases)
        cout << Solution().compressedString(s) << endl;

    return 0;
}
