#ifndef LEETCODE_0322_H
#define LEETCODE_0322_H

#include <vector>

using namespace std;

/**
 * dp[i][j]: 只使用前 i 个硬币凑成 j 金额，所需最小的硬币数量
 *
 * dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1)
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(vector<int>(amount + 1, amount + 1));

        dp[0] = 0;

        for (int i = 1; i < coins.size() + 1; ++i) {
            for (int j = coins[i - 1]; j < amount + 1; ++j) {
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

#endif //LEETCODE_0322_H
