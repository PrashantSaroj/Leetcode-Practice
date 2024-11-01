#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        int n = s.size();
        if (n <= 2)
        {
            return s;
        }

        char prev1 = s[0], prev2 = s[1];
        vector<char> fancy = {prev1, prev2};
        for (int i = 2; i < n; i++)
        {
            if (prev1 != s[i] || prev2 != s[i])
            {
                fancy.push_back(s[i]);
            }
            prev1 = prev2;
            prev2 = s[i];
        }
        return string(fancy.begin(), fancy.end());
    }
};

int main()
{
    vector<string> testCases = {
        "leeetcode",
        "aaabaaaa",
        "aab",
    };

    for (auto &t : testCases)
    {
        cout << Solution().makeFancyString(t) << endl;
    }

    return 0;
}
