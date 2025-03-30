#include <bits/stdc++.h>

#include "utils/PrintVector.cpp"
using namespace std;

#define NUM_ALPHA 26

class Solution {
    int N;
    int lastInd[NUM_ALPHA];
    vector<int> partSizes;

    void partitionHelper(string& s, int start) {
        if (start >= N) return;

        int i = start, end = start + 1;
        while (end < N && i < end) {
            int curEnd = lastInd[s[i] - 'a'];
            if (curEnd >= end) end = curEnd + 1;
            i++;
        }
        partSizes.push_back(end - start);
        partitionHelper(s, end);
    }

   public:
    vector<int> partitionLabels(string& s) {
        N = s.size();
        for (int i = 0; i < N; i++) lastInd[s[i] - 'a'] = i;
        partitionHelper(s, 0);
        return partSizes;
    }
};

int main() {
    vector<string> testCases = {
        "caedbdedda",
        "ababcbacadefegdehijhklij",
        "eccbbbbdec",
    };
    for (auto& t : testCases) printVector(Solution().partitionLabels(t));
}
