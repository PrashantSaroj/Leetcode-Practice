#include <bits/stdc++.h>
using namespace std;

class CustomStack {
    int *arr;
    int top, MAXSIZE;

   public:
    CustomStack(int maxSize) {
        arr = new int[maxSize];
        MAXSIZE = maxSize;
        top = 0;
    }

    void push(int x) {
        if (top < MAXSIZE) {
            arr[top++] = x;
        }
    }

    int pop() {
        return top ? arr[--top] : -1;
    }

    void increment(int k, int val) {
        int count = min(k, top);
        for (int i = 0; i < count; i++) {
            arr[i] += val;
        }
    }

    ~CustomStack() {
        delete[] arr;
    }
};

int main() {
    return 0;
}
