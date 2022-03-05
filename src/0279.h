#ifndef LEETCODE_0279_H
#define LEETCODE_0279_H

#include <vector>

using namespace std;

/**
 * dp[i]: 和为 i 的完全平方数的最少数量
 *
 * dp[i] = min(dp[i-1], dp[i-4], dp[i-9], ...,dp[i-k]) + 1
 * k: 满足 i-k >= 0 的最大完全平方数
 *
 * dp[0] = 0
 */

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; i - j*j >= 0; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

#endif //LEETCODE_0279_H
