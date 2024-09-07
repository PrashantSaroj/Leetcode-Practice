#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<char> prefix(string &str1, vector<char> &currPrefix) {
        vector<char> prefix;
        int maxPrefixLen = min(str1.size(), currPrefix.size());
        for (int i = 0; i < maxPrefixLen; i++) {
            if (str1[i] == currPrefix[i]) {
                prefix.push_back(str1[i]);
            } else {
                break;
            }
        }
        return prefix;
    }

   public:
    string longestCommonPrefix(vector<string> &strs) {
        vector<char> currPrefix(strs[0].begin(), strs[0].end());
        for (int i = 1; i < strs.size(); i++) {
            currPrefix = prefix(strs[i], currPrefix);
            if (currPrefix.size() == 0) {
                break;
            }
        }
        string retval(currPrefix.begin(), currPrefix.end());
        return retval;
    }
};

int main() {
    vector<string> str1{"flower", "flow", "flight"};
    vector<string> str2{"dog", "racecar", "car"};
    Solution sol;
    cout << sol.longestCommonPrefix(str1) << endl
         << sol.longestCommonPrefix(str2) << endl;
    return 0;
}