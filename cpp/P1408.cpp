#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

class Solution {
   public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> subStrings;
        for (int i = 0, N = words.size(); i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    if (words[j].find(words[i]) != words[j].npos) {
                        subStrings.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return subStrings;
    }
};

int main() {
    vector<vector<string>> testCases = {
        {"mass", "as", "hero", "superhero"},
        {"leetcode", "et", "code"},
        {"blue", "green", "bu"},
    };

    for (auto& t : testCases)
        printVector(Solution().stringMatching(t));
    return 0;
}
