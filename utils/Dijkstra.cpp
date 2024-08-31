#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
#define edge pair<int, int>

class Dijkstra {
   public:
    int shortestPath(int n, int src, int dst, vector<edge> adj[]) {
        vector<int> dist(n, INF);
        priority_queue<edge, vector<edge>, greater<edge>> minHeap;

        dist[src] = 0;
        minHeap.push({0, src});

        while (!minHeap.empty()) {
            auto [currShortestPath, curr] = minHeap.top();
            minHeap.pop();

            if (curr == dst) {
                break;
            }

            for (auto [weight, neighbor] : adj[curr]) {
                if (weight + currShortestPath < dist[neighbor]) {
                    dist[neighbor] = weight + currShortestPath;
                    minHeap.push({dist[neighbor], neighbor});
                }
            }
        }
        return dist[dst];
    }
};
