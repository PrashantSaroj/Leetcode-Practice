#include <bits/stdc++.h>
using namespace std;

class Solution {
    void swap(vector<int>& nums, int i1, int i2) {
        int n1 = nums[i1], n2 = nums[i2];
        nums[i2] = n1;
        nums[i1] = n2;
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivotIndex = left + rand() % (right - left + 1);
        swap(nums, right, pivotIndex);

        int pivotPos = left;
        for (int i = left; i <= right; i++) {
            if (nums[i] < nums[right]) swap(nums, i, pivotPos++);
        }
        swap(nums, pivotPos, right);
        return pivotPos;
    }

    int selectK(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        int pivotPos = partition(nums, left, right);

        if (pivotPos == k) return nums[pivotPos];

        if (pivotPos > k)
            return selectK(nums, left, pivotPos - 1, k);
        else
            return selectK(nums, pivotPos + 1, right, k);
    }

   public:
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();
        return selectK(nums, 0, N - 1, N - k);
    }
};

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{3, 2, 1, 5, 6, 4}, 2},
        {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4}};

    for (auto& t : testCases)
        cout << Solution().findKthLargest(t.first, t.second) << endl;
    return 0;
}
