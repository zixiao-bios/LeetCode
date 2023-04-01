#ifndef LEETCODE_1637_H
#define LEETCODE_1637_H

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points) {
        std::sort(points.begin(),
                  points.end(),
                  [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

        int ans = 0;
        for (int i = 1; i < points.size(); ++i) {
            ans = std::max(ans, points[i][0] - points[i - 1][0]);
        }
        return ans;
    }
};

#endif //LEETCODE_1637_H
