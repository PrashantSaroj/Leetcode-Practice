#include <bits/stdc++.h>
using namespace std;

class AllOne {
    unordered_map<string, int> stringCount;
    map<int, unordered_set<string>> minmaxHelper;

    void eraseKey(int keyInt, string keyStr) {
        minmaxHelper[keyInt].erase(keyStr);
        if (!minmaxHelper[keyInt].size()) {
            minmaxHelper.erase(keyInt);
        }
    }

    void insertKey(int keyInt, string keyStr) {
        if (!minmaxHelper.count(keyInt)) {
            minmaxHelper[keyInt] = unordered_set<string>();
        }
        minmaxHelper[keyInt].insert(keyStr);
    }

   public:
    AllOne() {
    }

    void inc(string key) {
        int newCount = ++stringCount[key];
        // string has been already seen
        if (newCount > 1) {
            eraseKey(newCount - 1, key);
        }
        insertKey(newCount, key);
    }

    void dec(string key) {
        int newCount = --stringCount[key];

        if (newCount) {
            insertKey(newCount, key);
        } else {
            stringCount.erase(key);
        }
        eraseKey(newCount + 1, key);
    }

    string getMaxKey() {
        string maxKey = "";
        if (minmaxHelper.size()) {
            maxKey = *(minmaxHelper.rbegin()->second).begin();
        }
        return maxKey;
    }

    string getMinKey() {
        string minKey = "";
        if (minmaxHelper.size()) {
            minKey = *(minmaxHelper.begin()->second).begin();
        }
        return minKey;
    }
};

int main() {
    return 0;
}
