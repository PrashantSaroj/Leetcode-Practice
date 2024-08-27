#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> graph(n);
        // connect initial edges
        for (int i = 0; i < n - 1; i++)
        {
            graph[i].push_back(i + 1);
        }

        int queriesCount = queries.size();
        vector<int> distances(n), retVal(queriesCount);

        // initialise distances
        for (int i = 0; i < n; i++)
        {
            distances[i] = n - i - 1;
        }

        // process queries
        for (int i = 0; i < queriesCount; i++)
        {
            int l = queries[i][0], r = queries[i][1];
            graph[l].push_back(r);

            // distances onward r+1 will not change
            for (int j = r; j >= 0; j--)
            {
                int minDistNeighbour = n;
                // iterate over all the neighbours of j and check their distances
                for (int neighbour : graph[j])
                {
                    minDistNeighbour = min(distances[neighbour], minDistNeighbour);
                }
                // cout << j << " " << minDistNeighbour << endl;
                distances[j] = min(distances[j], 1 + minDistNeighbour);
            }
            retVal[i] = distances[0];
        }
        return retVal;
    }
};

int main()
{
    int n, queriesCount;
    cin >> n >> queriesCount;

    vector<vector<int>> queries(queriesCount);

    int l, r;
    for (int i = 0; i < queriesCount; i++)
    {
        cin >> l >> r;
        queries[i].push_back(l);
        queries[i].push_back(r);
    }

    Solution sol = Solution();
    vector<int> retVal = sol.shortestDistanceAfterQueries(n, queries);
    for (int i = 0; i < queriesCount; i++)
    {
        cout << retVal[i] << endl;
    }
    return 0;
}
