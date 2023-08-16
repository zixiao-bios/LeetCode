#ifndef LEETCODE_2682_H
#define LEETCODE_2682_H

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> players(n, false);
        int p = 0, step = 1;
        while (!players[p]) {
            players[p] = true;
            p += step * k;
            p %= n;
            ++step;
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!players[i]) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

#endif //LEETCODE_2682_H
