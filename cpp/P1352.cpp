#include <bits/stdc++.h>
using namespace std;
const int K_MAX = 40000;

class ProductOfNumbers {
    int streamEnd = 0;
    vector<int> stream;

   public:
    ProductOfNumbers() {
        stream = vector<int>(K_MAX, 0);
    }

    void add(int num) {
        stream[streamEnd] = num;
        streamEnd = (streamEnd + 1) % K_MAX;
    }

    int getProduct(int k) {
        int product = 1;
        for (int i = 1; i <= k; i++) {
            product *= stream[(streamEnd - i + K_MAX) % K_MAX];
        }
        return product;
    }
};

int main() {
    return 0;
}
