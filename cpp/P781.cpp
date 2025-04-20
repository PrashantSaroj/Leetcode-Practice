#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numRabbits(vector<int>& answers) {
        int rabbits = 0;
        map<int, int> grouping;
        for (int ans : answers) grouping[ans]++;
        // go over each group and calculate
        for (auto& [key, value] : grouping) {
            int bucket = key + 1;
            rabbits += (value / bucket + (value % bucket != 0)) * bucket;
        }
        return rabbits;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 1, 2},
        {10, 10, 10},
    };
    for (auto& t : testCases) {
        printf("Num rabbits: %i\n", Solution().numRabbits(t));
    }
}
