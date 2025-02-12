#include <bits/stdc++.h>
using namespace std;

class Solution {
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

   public:
    int maximumSum(vector<int>& nums) {
        map<int, multiset<int>> sumBuckets;
        for (int n : nums)
            sumBuckets[digitSum(n)].insert(n);

        int maxSum = -1;
        for (map<int, set<int>>::reverse_iterator it = sumBuckets.rbegin(); it != sumBuckets.rend(); it++) {
            if ((it->second).size() >= 2) {
                int num1 = *(it->second).rbegin();
                int num2 = *(++(it->second).rbegin());
                maxSum = max(maxSum, num1 + num2);
            };
        }
        return maxSum;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {18, 43, 36, 13, 7},
        {10, 12, 19, 14},
    };

    for (auto& t : testCases)
        cout << Solution().maximumSum(t) << endl;
    return 0;
}
