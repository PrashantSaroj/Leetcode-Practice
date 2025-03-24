#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void balanceHeaps() {
        // invariant: maxHeap size == minHeap size or maxHeap size == minHeap size + 1
        int N1 = maxHeap.size(), N2 = minHeap.size();
        if (N1 > N2 + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (N2 > N1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

   public:
    MedianFinder() {}

    void addNum(int num) {
        // first run
        if (maxHeap.size() == 0) {
            maxHeap.push(num);
            return;
        }

        if (num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);
        balanceHeaps();
    }

    double findMedian() {
        if ((maxHeap.size() + minHeap.size()) & 1)
            return maxHeap.top();
        else
            return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};

int main() {
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    cout << m.findMedian() << endl;
    m.addNum(3);
    cout << m.findMedian() << endl;
}
