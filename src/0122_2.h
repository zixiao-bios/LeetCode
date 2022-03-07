#ifndef LEETCODE_0122_2_H
#define LEETCODE_0122_2_H

#include <vector>

using namespace std;

/**
 * dp[i][0]: 前 i 天结束时，持有股票为 0 时的最大收益
 * dp[i][1]: 前 i 天结束时，持有股票为 1 时的最大收益
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(vector<int>(2, 0));

        dp[1] = INT_MIN;

        for (int i = 1; i < n + 1; ++i) {
            dp[0] = max(dp[0], dp[1] + prices[i - 1]);
            dp[1] = max(dp[1], dp[0] - prices[i - 1]);
        }

        return dp[0];
    }
};

#endif //LEETCODE_0122_2_H
