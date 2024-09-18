#include <bits/stdc++.h>
#include "utils/PrintVector.cpp"
using namespace std;

bool customStringGreaterComparison(string &s1, string &s2) 
{
    if ((s1+s2) > (s2 + s1)) {
        return true;
    } else {
        return false;
    }
}

class Solution
{
    string removeTrailingZeros(string &s) {
        int i = 0;
        while(i < s.size() && s[i] == '0') {
            i++;
        }

        if (i == s.size()) {
            return "0";
        }
        return string(s.begin()+i, s.end());
    }

public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> numsString;
        for (int n: nums) {
            numsString.push_back(to_string(n));
        }
        sort(numsString.begin(), numsString.end(), customStringGreaterComparison);
        string ans;
        for (string num: numsString) {
            ans += num;
        }
        return removeTrailingZeros(ans);
    }
};

int main()
{
    vector<int> nums = {3,30,34,5,9,99,94};
    cout << Solution().largestNumber(nums) << endl;
    return 0;
}
