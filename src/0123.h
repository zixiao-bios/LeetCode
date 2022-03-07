#ifndef LEETCODE_0123_H
#define LEETCODE_0123_H

#include <vector>

using namespace std;

/**
 * dp[i][j][k]: 第 i 天结束时，买入 j 次且剩余股票为 k 时的最大收益 (k=1 or k=2)
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(2, 0));

        for (int j = 0; j < 3; ++j) {
            dp[j][1] = INT_MIN;
        }

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < 3; ++j) {
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i - 1]);
                dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i - 1]);
            }
        }

        return dp[2][0];
    }
};

#endif //LEETCODE_0123_H
