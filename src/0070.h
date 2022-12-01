#ifndef LEETCODE_0070_H
#define LEETCODE_0070_H

/**
 * dp[i]：爬到i阶的方法数
 *
 * dp[i] = dp[i-1] + dp[i-2]
 *
 * dp[1] = 1
 * dp[2] = 2
 */

#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i < n + 1; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

#endif //LEETCODE_0070_H
