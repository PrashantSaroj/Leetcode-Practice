#include <bits/stdc++.h>
using namespace std;

class Solution {
    void match(string& part, deque<char>& charStack, int K) {
        bool matched = true;
        stack<char> matchedChar;
        for (int j = K - 1; j >= 0; j--) {
            if (part[j] != charStack.back()) {
                matched = false;
                break;
            }
            matchedChar.push(charStack.back());
            charStack.pop_back();
        }

        if (!matched) {
            while (!matchedChar.empty()) {
                charStack.push_back(matchedChar.top());
                matchedChar.pop();
            }
        }
    }

   public:
    string removeOccurrences(string& s, string& part) {
        int N = s.size(), K = part.size();
        deque<char> charStack;
        for (int i = 0; i < N; i++) {
            charStack.push_back(s[i]);
            if (s[i] == part[K - 1] && charStack.size() >= K - 1)
                match(part, charStack, K);
        }

        return string(charStack.begin(), charStack.end());
    }
};

int main() {
    vector<pair<string, string>> testCases = {
        {"ixcupqoixcupqokevnpokevnpoknqywmlhevgc", "ixcupqokevnpo"}
        // {"aabcbcd", "abc"},
        // {"daabcbaabcbc", "abc"},
        // {"axxxxyyyyb", "xy"},
    };

    for (auto& t : testCases)
        cout << Solution().removeOccurrences(t.first, t.second) << endl;
    return 0;
}
