#ifndef LEETCODE_0064_H
#define LEETCODE_0064_H

#include <vector>

using namespace std;

/**
 * dp[i]: 从 grid[0][0] 到 grid[row][i] 的最小代价
 *
 * if (node 在左上角)
 *      dp[i] = node.val
 * else if (node 在第一行)
 *      dp[i] = dp[i-1] + node.val
 * else if (node 在第一列)
 *      dp[i] = dp[i] + node.val
 * else
 *      dp[i] = min(dp[i], dp[i-1]) + node.val
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size(), 0);

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i == 0 and j == 0) {
                    dp[j] = grid[i][j];
                } else if (i == 0) {
                    dp[j] = dp[j - 1] + grid[i][j];
                } else if (j == 0) {
                    dp[j] = dp[j] + grid[i][j];
                } else {
                    dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
                }
            }
        }

        return dp[grid[0].size() - 1];
    }
};

#endif //LEETCODE_0064_H
