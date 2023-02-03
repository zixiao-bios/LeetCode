#ifndef LEETCODE_0096_H
#define LEETCODE_0096_H

/**
 * dp[i]: n=i时，不同的二叉搜索树的个数
 *
 * dp[i] = dp[0]*dp[i-1] + dp[1]*dp[i-2] + ... + dp[i-1]*dp[0]
 *
 * dp[0] = dp[1] = 1
 */

#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }

        return dp[n];
    }
};

#endif //LEETCODE_0096_H
