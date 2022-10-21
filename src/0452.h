#ifndef LEETCODE_0452_H
#define LEETCODE_0452_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

        int right = INT_MAX;
        int count = 0;

        for (auto &each: points) {
            if (each[0] > right) {
                // shot
                ++count;
                right = INT_MAX;
            }

            right = min(right, each[1]);

        }
        ++count;

        return count;
    }
};

#endif //LEETCODE_0452_H
