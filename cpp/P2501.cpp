#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        unordered_set<long> numsSet(nums.begin(), nums.end());
        int longestSeq = -1;

        for (int n : nums)
        {
            int curSeq = 1;
            long next = (long)n * n;
            while (numsSet.find(next) != numsSet.end())
            {
                next = next * next;
                curSeq++;
            }

            if (curSeq > 1)
            {
                longestSeq = max(longestSeq, curSeq);
            }
        }

        return longestSeq;
    }
};

int main()
{
    vector<vector<int>> testCases = {
        {4, 3, 6, 16, 8, 2},
        {2, 3, 5, 6, 7},
    };

    for (auto &t : testCases)
    {
        cout << Solution().longestSquareStreak(t) << endl;
    }

    return 0;
}
