#ifndef LEETCODE_0714_H
#define LEETCODE_0714_H

#include <vector>

using namespace std;

/**
 * dp[i][j]: 第 i 天结束时，持有 j 个股票，的最大收益
 */

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> dp(2, 0);

        dp[1] = -prices[0];

        for (int i = 1; i < n + 1; ++i) {
            dp[0] = max(dp[0], dp[1] + prices[i - 1] - fee);
            dp[1] = max(dp[1], dp[0] - prices[i - 1]);
        }

        return dp[0];
    }
};

#endif //LEETCODE_0714_H
