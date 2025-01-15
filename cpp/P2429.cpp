#include <bits/stdc++.h>
using namespace std;

class Solution {
    int countBits(int num) {
        int count = 0;
        while (num) {
            if (num & 1) count++;
            num = num >> 1;
        }
        return count;
    }

    int removeLeastSignificant(int num, int bitsCount) {
        int tracker = 1;
        while (bitsCount) {
            if (num & tracker) {
                num = (num ^ tracker);
                bitsCount--;
            }
            tracker = tracker << 1;
        }
        return num;
    }

    int addLeastSignificant(int num, int bitsCount) {
        int tracker = 1;
        while (bitsCount) {
            if (!(num & tracker)) {
                num = (num | tracker);
                bitsCount--;
            }
            tracker = tracker << 1;
        }
        return num;
    }

   public:
    int minimizeXor(int num1, int num2) {
        int N1 = countBits(num1), N2 = countBits(num2);

        if (N1 == N2) {
            return num1;
        } else if (N1 > N2) {
            return removeLeastSignificant(num1, N1 - N2);
        } else {
            return addLeastSignificant(num1, N2 - N1);
        }
    }
};

int main() {
    vector<pair<int, int>> testCases = {
        {3, 5},
        {1, 12},
    };

    for (auto &t : testCases)
        cout << Solution().minimizeXor(t.first, t.second) << endl;
    return 0;
}
