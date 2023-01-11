#ifndef LEETCODE_0063_H
#define LEETCODE_0063_H

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp_pre(n, 0);
        vector<int> dp(n, 0);

        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j]) {
                break;
            }
            dp_pre[j] = 1;
        }

        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] or dp_pre[0] == 0) {
                dp[0] = 0;
            } else {
                dp[0] = 1;
            }

            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j]) {
                    dp[j] = 0;
                } else {
                    dp[j] = dp_pre[j] + dp[j - 1];
                }
            }

            dp_pre = dp;
        }

        return dp_pre[n - 1];
    }
};

#endif //LEETCODE_0063_H
