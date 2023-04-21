#ifndef LEETCODE_1043_H
#define LEETCODE_1043_H

/**
 * dp[i][j]: 只考虑 arr 的前 i 个元素，其末尾子数组的长度为 j，此时其末尾子数组的最大值
 *
 * dp[i][j] = max( dp[i-1][j-1], arr[i-1] )     , j <= i and j > 1
 *          = arr[i-1]                          , j == 1
 *
 * dp[0][0] = -inf
 */

#include <vector>

using std::vector;

class Solution {
public:
    vector<int32_t> mem;

    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();
        mem = vector(n + 1, -1);
        vector<vector<int32_t>> dp(n + 1, vector(k + 1, INT32_MIN));

        for (int i = 1; i <= n; ++i) {
            dp[i][1] = arr[i - 1];
            for (int j = 2; j <= std::min(i, k); ++j) {
                dp[i][j] = std::max(dp[i - 1][j - 1], arr[i - 1]);
            }
        }
        return dfs(dp, n);
    }

    // 返回 arr 的前 n 个元素范围内的答案值
    int32_t dfs(const vector<vector<int32_t>> &data, int n) {
        if (n == 0) {
            return 0;
        }

        if (mem[n] != -1) {
            return mem[n];
        }

        int ans = 0;
        for (int j = 1; j < std::min(static_cast<int>(data[0].size()), n + 1); ++j) {
            ans = std::max(ans, data[n][j] * j + dfs(data, n - j));
        }
        mem[n] = ans;
        return ans;
    }
};

#endif //LEETCODE_1043_H
