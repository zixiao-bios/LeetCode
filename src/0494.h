#ifndef LEETCODE_0494_H
#define LEETCODE_0494_H

/**
 * 0 - 1 背包，n 个物品，第 i 个物品重量为 w[i]，价值为 v[i]，背包容量为 t，求可装下的最大价值
 *
 * dp[i][j]: 只考虑前 i 个物品，且背包容量为 j 时，可装下的最大价值
 * dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i])
 *
 * 先将数组所有元素取负号，然后选择部分元素变为正号，使得整体和为target
 * 设 原数组和为 sum，添加正号元素之和为 pos，则添加负号元素之和为 sum-pos
 * 满足 pos - (sum - pos) = 2 * pos - sum = target
 * pos = (target + sum) / 2
 * 由于元素都是正整数，因此 target + sum 不是正偶数时，无解
 * 题目转为：在数组中选择若干元素，使得和为给定值
 *
 * dp[i][j]: 只考虑前 i 个元素，且求和为 j，可行解的数量
 * dp[i][j] = dp[i-1][j] + dp[i-1][j-num[i]]    , j - num[i] >= 0
 *          = dp[i-1][j]                        , else
 *
 * dp[0][j] = 1 , j = 0
 *          = 0 , j > 0
 */

#include <vector>
#include <numeric>

using std::vector;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        auto n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int t = target + sum;
        if (t < 0 or t % 2 != 0) {
            return 0;
        }

        t /= 2;
        vector dp_pre = vector(t + 1, 0);
        vector dp = vector(t + 1, 0);
        dp_pre[0] = 1;

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j < t + 1; ++j) {
                if (j - nums[i - 1] >= 0) {
                    dp[j] = dp_pre[j] + dp_pre[j - nums[i - 1]];
                } else {
                    dp[j] = dp_pre[j];
                }
            }
            std::swap(dp, dp_pre);
        }
        return dp_pre[t];
    }
};

#endif //LEETCODE_0494_H
