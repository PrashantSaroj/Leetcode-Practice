#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int WIN_SIZE = 26;

    bool isWindowEqual(vector<int> &arr1, vector<int> &arr2) {
        for (int i = 0; i < WIN_SIZE; i++)
            if (arr1[i] != arr2[i])
                return false;
        return true;
    }

    vector<int> createWindow(string &s1) {
        vector<int> win(WIN_SIZE, 0);
        for (char c : s1)
            win[c - 'a'] += 1;
        return win;
    }

   public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        string firstWindow = s2.substr(0, n1);

        vector<int> winFixed = createWindow(s1);
        vector<int> winSlide = createWindow(firstWindow);
        int l = 0, r = 0;
        for (int i = 0, n2 = s2.size() - n1; i <= n2; i++) {
            winSlide[s2[l] - 'a'] -= 1;
            winSlide[s2[r] - 'a'] += 1;
            if (isWindowEqual(winFixed, winSlide))
                return true;
            l = i;
            r = i + n1;
        }
        return false;
    }
};

typedef pair<string, string> tc;

int main() {
    vector<tc> testCases = {
        {"adc", "dcda"},
        {"ab", "eidbaooo"},
        {"ab", "eidboaoo"}};

    for (auto &t : testCases) {
        cout << Solution().checkInclusion(t.first, t.second) << endl;
    }

    return 0;
}
