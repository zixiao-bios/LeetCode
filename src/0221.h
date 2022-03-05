#ifndef LEETCODE_0221_H
#define LEETCODE_0221_H

#include <vector>

using namespace std;

/**
 * dp[i][j]: 以 matrix[i][j] 为右下角的最大正方形的*边长*
 *
 * if (matrix[i][j] == 0)
 *      dp[i][j] = 0
 * else
 *      dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
 */

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxLen = 0;

        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 or j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    if (matrix[i][j] == '0') {
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                    }
                }
                maxLen = max(maxLen, dp[i][j]);
            }
        }

        return maxLen * maxLen;
    }
};

#endif //LEETCODE_0221_H
