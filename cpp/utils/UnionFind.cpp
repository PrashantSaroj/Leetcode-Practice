#include <map>
using namespace std;

template <typename T>
class UnionFind {
    map<T, T> parent;

   public:
    UnionFind() {}

    T find(T node) {
        if (parent[node] == node) {
            return node;
        } else {
            T result = find(parent[node]);
            parent[node] = result;
            return result;
        }
    }

    void merge(T node1, T node2) {
        parent[find(node1)] = find(node2);
    }

    void insert(T node) {
        parent[node] = node;
    }

    int countDisjointSets() {
        int count = 0;
        for (auto it : parent) {
            if (it.first == it.second) {
                count++;
            }
        }
        return count;
    }
};
