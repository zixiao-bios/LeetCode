#ifndef LEETCODE_0056_H
#define LEETCODE_0056_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        int left = intervals[0][0], right = intervals[0][1];
        vector<vector<int>> ans;
        for (auto &each: intervals) {
            if (each[0] > right) {
                // interval end
                ans.push_back({left, right});
                left = each[0];
                right = each[1];
            } else {
                // interval expand
                right = max(right, each[1]);
            }
        }
        ans.push_back({left, right});

        return ans;
    }
};

#endif //LEETCODE_0056_H
