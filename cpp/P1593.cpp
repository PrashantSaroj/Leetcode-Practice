#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int strSize;
    unordered_set<string> uniqs;
    string s;

    bool canAdd(int startPos, int len)
    {
        string subStr = s.substr(startPos, len);
        if (uniqs.find(subStr) != uniqs.end())
        {
            return false;
        }
        uniqs.insert(subStr);
        return true;
    }

    int findSplit(int splitter)
    {
        int startPos = 0;
        for (int i = 0; i < strSize; i++)
        {
            if ((1 << i) & splitter)
            {
                if (!canAdd(startPos, i - startPos + 1))
                {
                    return 0;
                }
                startPos = i + 1;
            }
        }

        if (!canAdd(startPos, strSize - startPos))
        {
            return 0;
        }
        return uniqs.size();
    }

public:
    int maxUniqueSplit(string s)
    {
        int maxSplits = 0;
        strSize = s.size();
        this->s = s;
        for (int i = 0, N = 1 << (strSize - 1); i < N; i++)
        {
            uniqs = {};
            maxSplits = max(maxSplits, findSplit(i));
        }
        return maxSplits;
    }
};

int main()
{
    vector<string> testCases = {
        "ababccc",
        "aba",
        "aa",
    };

    for (string &s : testCases)
    {
        cout << Solution().maxUniqueSplit(s) << endl;
    }
    return 0;
}
