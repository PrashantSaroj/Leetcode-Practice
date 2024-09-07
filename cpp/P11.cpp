#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1;

        int retVal = 0;
        while (l < r)
        {
            retVal = max(retVal, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return retVal;
    }
};

int main()
{
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << Solution().maxArea(height) << endl;
    return 0;
}
