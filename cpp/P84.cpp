#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> lSmaller, rSmaller;

    void fillSmallerLeft(vector<int>& heights, int N) {
        stack<int> monotonic;
        for (int i = 0; i < N; i++) {
            while (!monotonic.empty() && heights[monotonic.top()] >= heights[i]) monotonic.pop();
            if (!monotonic.empty()) lSmaller[i] = monotonic.top();
            monotonic.push(i);
        }
    }

    void fillSmallerRight(vector<int>& heights, int N) {
        stack<int> monotonic;
        for (int i = N - 1; i >= 0; i--) {
            while (!monotonic.empty() && heights[monotonic.top()] >= heights[i]) monotonic.pop();
            if (!monotonic.empty()) rSmaller[i] = monotonic.top();
            monotonic.push(i);
        }
    }

   public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        lSmaller.resize(N, -1);
        rSmaller.resize(N, N);

        fillSmallerLeft(heights, N);
        fillSmallerRight(heights, N);

        int maxRectangle = 0;
        for (int i = 0; i < N; i++) {
            int rectWidth = rSmaller[i] - lSmaller[i] - 1;
            maxRectangle = max(maxRectangle, heights[i] * rectWidth);
        }
        return maxRectangle;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {2, 1, 5, 6, 2, 3},
        {2, 4},
    };
    for (auto& t : testCases) cout << Solution().largestRectangleArea(t) << endl;
}
