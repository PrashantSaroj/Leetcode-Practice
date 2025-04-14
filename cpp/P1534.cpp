#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int goodTriplets = 0;
        for (int i = 0, N = arr.size(); i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[k] - arr[i]) <= c) {
                        goodTriplets++;
                    }
                }
            }
        }
        return goodTriplets;
    }
};

int main() {
    vector<int> arr = {3, 0, 1, 1, 9, 7};
    printf("Good triplets: %i\n", Solution().countGoodTriplets(arr, 7, 2, 3));
}
