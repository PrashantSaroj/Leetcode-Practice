#include <bits/stdc++.h>
using namespace std;

struct Friend {
    int id, arrival, leaving, chair;
};

bool arrivalComparator(const Friend &f1, const Friend &f2) {
    return f1.arrival < f2.arrival;
}

class leavingComparator {
   public:
    int operator()(const Friend &f1, const Friend &f2) {
        return f1.leaving > f2.leaving;
    }
};

class Solution {
   public:
    int smallestChair(vector<vector<int>> &times, int targetFriend) {
        int N = times.size();
        Friend friends[N];
        for (int i = 0; i < N; i++)
            friends[i] = {i, times[i][0], times[i][1], -1};

        // sort by arrival time
        sort(friends, friends + N, arrivalComparator);

        priority_queue<int, vector<int>, greater<int>> chairHeap;
        for (int i = 0; i < N; i++)
            chairHeap.push(i);

        priority_queue<Friend, vector<Friend>, leavingComparator> friendHeap;
        for (int i = 0; i < N; i++) {
            Friend cur = friends[i];
            while (friendHeap.size() && friendHeap.top().leaving <= cur.arrival) {
                chairHeap.push(friendHeap.top().chair);
                friendHeap.pop();
            }

            if (targetFriend == cur.id) return chairHeap.top();

            cur.chair = chairHeap.top();
            friendHeap.push(cur);
            chairHeap.pop();
        }
    }
};

int main() {
    int targetFriend = 1;
    vector<vector<int>> times = {{1, 4}, {2, 3}, {4, 6}};

    cout << Solution().smallestChair(times, targetFriend) << endl;

    return 0;
}
