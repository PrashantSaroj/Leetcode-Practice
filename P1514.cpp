#include <bits/stdc++.h>

using namespace std;

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
            if (succProb[i] > 0.0)
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
}
