#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumSwap(int num) {
        string numStr1 = to_string(num);
        string numStr2 = numStr1;
        int N = numStr1.size();

        sort(numStr1.begin(), numStr1.end(), greater<char>());

        char smol = '\0', bigg = '\0';
        for (int i = 0; i < N; i++)
            if (numStr1[i] != numStr2[i]) {
                smol = numStr2[i];
                bigg = numStr1[i];
                numStr2[i] = bigg;
                break;
            }

        // make the last instance of bigg = smol
        if (smol) {
            for (int i = N - 1; i >= 0; i--) {
                if (numStr2[i] == bigg) {
                    numStr2[i] = smol;
                    break;
                }
            }
        }

        return stoi(numStr2);
    }
};

int main() {
    vector<int> testCases = {98368, 2736, 9973};
    for (auto n : testCases)
        cout << Solution().maximumSwap(n) << endl;

    return 0;
}
