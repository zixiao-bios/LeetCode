#ifndef LEETCODE_0188_H
#define LEETCODE_0188_H

#include <vector>

using namespace std;

/**
 * dp[i][j][0]: 前 i 天进行 j 次交易，且不持有股票的最大收益
 * dp[i][j][1]: 前 i 天进行 j 次交易，且持有股票的最大收益
 */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k = min(k, n / 2);
        vector<vector<int>> dp(k + 1, vector<int>(2, 0));

        for (int j = 0; j < k + 1; ++j) {
            dp[j][1] = INT_MIN;
        }

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < k + 1; ++j) {
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i - 1]);
                dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i - 1]);
            }
        }

        return dp[k][0];
    }
};

#endif //LEETCODE_0188_H
