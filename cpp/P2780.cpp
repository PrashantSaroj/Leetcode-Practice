#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dominantElement(vector<int>& nums) {
        int domEle = -1, domFreq = 0;
        for (int n : nums) {
            if (n == domEle) {
                domFreq++;
            } else {
                domFreq--;
                if (domFreq < 0) {
                    domFreq = 0;
                    domEle = n;
                }
            }
        }
        return domEle;
    }

    int findFreq(vector<int>& nums, int target) {
        int freq = 0;
        for (int n : nums) freq += target == n;
        return freq;
    }

   public:
    int minimumIndex(vector<int>& nums) {
        int domEle = dominantElement(nums);
        int domFre = findFreq(nums, domEle), curFreq = 0;
        for (int i = 0, N = nums.size(); i < N - 1; i++) {
            if (nums[i] == domEle) curFreq++;
            int split1Size = i + 1, split1Freq = curFreq;
            int split2Size = N - (i + 1), split2Freq = domFre - split1Freq;
            if (split1Freq > (split1Size >> 1) && split2Freq > (split2Size >> 1)) return i;
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 2, 2},
        {2, 1, 3, 1, 1, 1, 7, 1, 2, 1},
        {3, 3, 3, 3, 7, 2, 2},
    };

    for (auto& t : testCases) {
        cout << Solution().minimumIndex(t) << endl;
    }
}
