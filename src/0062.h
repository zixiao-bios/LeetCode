#ifndef LEETCODE_0062_H
#define LEETCODE_0062_H

/**
 * dp[i][j]: 走到 (i, j) 时的路径总和
 *
 * dp[i][j] = dp[i-1][j] + dp[i][j-1]
 *
 * dp[0][j] = dp[i][0] = 1
 */

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        vector<int> dp_pre(n, 1);

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] = dp_pre[j] + dp[j - 1];
            }
            dp_pre = dp;
        }

        return dp[n - 1];
    }
};

#endif //LEETCODE_0062_H
