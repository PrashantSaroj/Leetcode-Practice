#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int dp[m][n];
        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = 0; i < m; i++)
            {
                dp[i][j] = 0;
                if (j + 1 < n)
                {
                    if (i > 0 && grid[i][j] < grid[i - 1][j + 1])
                    {
                        dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j + 1]);
                    }
                    if (grid[i][j] < grid[i][j + 1])
                    {
                        dp[i][j] = max(dp[i][j], 1 + dp[i][j + 1]);
                    }
                    if (i + 1 < m && grid[i][j] < grid[i + 1][j + 1])
                    {
                        dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j + 1]);
                    }
                }
            }
        }

        int ans = dp[0][0];
        for (int i = 1; i < m; i++)
        {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
    cout << Solution().maxMoves(grid) << endl;
    return 0;
}
