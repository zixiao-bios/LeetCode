#ifndef LEETCODE_0309_H
#define LEETCODE_0309_H

#include <vector>

using namespace std;

/**
 * dp[i][j]: 第 i 天结束时，持有股票为 j 时的最大收益
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(2, 0));

        dp[0][1] = dp[1][1] = INT_MIN;

        for (int i = 1; i < n + 1; ++i) {
            dp[2][0] = max(dp[1][0], dp[1][1] + prices[i - 1]);
            dp[2][1] = max(dp[1][1], dp[0][0] - prices[i - 1]);

            swap(dp[0], dp[1]);
            swap(dp[1], dp[2]);
        }

        return dp[1][0];
    }
};

#endif //LEETCODE_0309_H
