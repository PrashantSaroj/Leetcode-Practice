#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
    int MAXSIZE;
    int *deque;
    int front, currSize;

   public:
    MyCircularDeque(int k) {
        MAXSIZE = k;
        deque = new int[k];
        front = currSize = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        deque[front] = value;
        front = (front + 1) % MAXSIZE;
        currSize++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        int rear = (front - currSize - 1 + MAXSIZE) % MAXSIZE;
        deque[rear] = value;
        currSize++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        currSize--;
        front = (front - 1 + MAXSIZE) % MAXSIZE;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        currSize--;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : deque[(front - 1 + MAXSIZE) % MAXSIZE];
    }

    int getRear() {
        return isEmpty() ? -1 : deque[(front - currSize + MAXSIZE) % MAXSIZE];
    }

    bool isEmpty() {
        return currSize == 0;
    }

    bool isFull() {
        return currSize == MAXSIZE;
    }

    ~MyCircularDeque() {
        delete[] deque;
    }
};

int main() {
    return 0;
}
