#ifndef LEETCODE_0452_H
#define LEETCODE_0452_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),[](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

        int ans = 0;
        int end = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > end) {
                ++ans;
                end = points[i][1];
            } else {
                end = min(end, points[i][1]);
            }
        }

        ++ans;

        return ans;
    }
};

#endif //LEETCODE_0452_H
