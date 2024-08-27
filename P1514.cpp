#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

class Dijkstra
{
    int n;
    vector<vector<pair<int, double>>> adj;

public:
    Dijkstra(int n, vector<vector<int>> &edges, vector<double> &weights)
    {
        this->n = n;
        adj.resize(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(pair(v, weights[i]));
            adj[v].push_back(pair(u, weights[i]));
        }
    }

    double findShortestPath(int src, int dst)
    {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> Q;
        vector<double> dist(this->n, INF);

        Q.push(pair(0, src));
        dist[src] = 0;

        while (!Q.empty())
        {
            int u = Q.top().second;
            Q.pop();

            for (auto neighbor : adj[u])
            {
                if (dist[neighbor.first] > dist[u] + neighbor.second)
                {
                    dist[neighbor.first] = dist[u] + neighbor.second;
                    Q.push(pair(dist[neighbor.first], neighbor.first));
                }
            }
        }
        return dist[dst];
    }
};

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<double> transWeights;
        vector<vector<int>> transEdges;
        for (int i = 0; i < edges.size(); i++)
        {
            if (succProb[i] > 0)
            {
                transEdges.push_back(edges[i]);
                transWeights.push_back(abs(log(succProb[i])));
            }
        }

        Dijkstra d(n, transEdges, transWeights);

        double minWeight = d.findShortestPath(start_node, end_node);
        return exp(-minWeight);
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    Solution sol;

    int start = 0, end = 2;
    cout << sol.maxProbability(n, edges, succProb, start, end) << endl;

    return 0;
}
