#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long totalSkill = accumulate(skill.begin(), skill.end(), (long)0);
        if (totalSkill % (n / 2)) {
            return -1;
        }

        int teamSkill = totalSkill / (n / 2);
        unordered_map<int, int> freq;
        for (int s : skill) freq[s] += 1;

        long long chemistry = 0;
        for (int s : skill) {
            if (freq[s])
                freq[s] -= 1;
            else
                continue;

            int teamMember = teamSkill - s;
            if (freq[teamMember]) {
                freq[teamMember] -= 1;
                chemistry += (s * teamMember);
            } else
                return -1;
        }
        return chemistry;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {3, 2, 5, 1, 3, 4},
        {3, 4},
        {1, 1, 2, 3}};
    for (auto& t : testCases) {
        cout << Solution().dividePlayers(t) << endl;
    }

    return 0;
}
