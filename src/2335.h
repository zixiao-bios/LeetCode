#ifndef LEETCODE_2335_H
#define LEETCODE_2335_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int fillCups(vector<int> &amount) {
        priority_queue<int> pq;
        for (auto &each: amount) {
            if (each != 0) {
                pq.push(each);
            }
        }

        int ans = 0;
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            --a, --b;
            if (a > 0) {
                pq.push(a);
            }
            if (b > 0) {
                pq.push(b);
            }

            ++ans;
        }

        if (pq.size() == 1) {
            ans += pq.top();
        }

        return ans;
    }
};


#endif //LEETCODE_2335_H
