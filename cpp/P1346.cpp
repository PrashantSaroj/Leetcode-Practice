#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool checkIfExist(vector<int>& arr) {
        unordered_multiset<int> existence(arr.begin(), arr.end());
        if (existence.count(0) > 1) {
            return true;
        } else {
            existence.erase(0);
        }

        for (int n : arr) {
            if (existence.find(2 * n) != existence.end()) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
