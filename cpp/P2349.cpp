#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
    unordered_map<int, int> index2Num;
    unordered_map<int, set<int>> num2Indices;

   public:
    NumberContainers() {
    }

    void change(int index, int number) {
        if (index2Num.find(index) != index2Num.end()) {
            int oldNum = index2Num[index];
            num2Indices[oldNum].erase(index);
            if (!num2Indices[oldNum].size()) {
                num2Indices.erase(oldNum);
            }
        }
        index2Num[index] = number;
        num2Indices[number].insert(index);
    }

    int find(int number) {
        if (num2Indices.find(number) != num2Indices.end()) {
            return *num2Indices[number].begin();
        }
        return -1;
    }
};

int main() {
    return 0;
}
