#ifndef LEETCODE_2500_H
#define LEETCODE_2500_H

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>> &grid) {
        for (auto &each: grid) {
            std::sort(each.begin(), each.end());
        }

        int ans = 0;
        auto m = grid.size(), n = grid[0].size();
        for (int j = 0; j < n; ++j) {
            int max_num = grid[0][j];
            for (int i = 1; i < m; ++i) {
                max_num = std::max(max_num, grid[i][j]);
            }
            ans += max_num;
        }
        return ans;
    }
};

#endif //LEETCODE_2500_H
