#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printVector(vector<T> v) {
    for (T &t : v) {
        cout << t << " ";
    }
    cout << endl;
}

template <typename T>
void printVecOfVector(vector<vector<T>> v) {
    for (vector<T> &t : v) {
        printVector(t);
    }
    cout << endl;
}
