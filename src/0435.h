#ifndef LEETCODE_0435_H
#define LEETCODE_0435_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.size() < 2) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

        int ans = 0;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < lastEnd) {
                ++ans;
            } else {
                lastEnd = intervals[i][1];
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0435_H
