#ifndef LEETCODE_OFFER47_H
#define LEETCODE_OFFER47_H

#include <vector>

using std::vector;

class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0), dp_last(n, 0);

        dp_last[n - 1] = grid[m - 1][n - 1];
        for (int j = n - 2; j >= 0; --j) {
            dp_last[j] = grid[m - 1][j] + dp_last[j + 1];
        }

        for (int i = m - 2; i >= 0; --i) {
            dp[n - 1] = grid[i][n - 1] + dp_last[n - 1];
            for (int j = n - 2; j >= 0; --j) {
                dp[j] = grid[i][j] + std::max(dp[j + 1], dp_last[j]);
            }
            dp_last.swap(dp);
        }
        return dp_last[0];
    }
};

#endif //LEETCODE_OFFER47_H
