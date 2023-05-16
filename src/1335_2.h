#ifndef LEETCODE_1335_2_H
#define LEETCODE_1335_2_H

/**
 * dp[i][j]: 从索引为 i 的工作开始，制定 j 天的计划表，工作计划的最低难度值
 *
 * 假设第一天完成的任务数为 k，则第一天完成的任务范围为 [i, i+k-1]
 * dp[i][j] = min( dp[i+k][j-1] + max(jobDiff[i:i+k-1]) )     , 1 <= k <= n-i
 *
 * dp[n][0] = 0
 * dp[n][j] = -1
 *
 * dp[n][0] = 0
 * dp[i][0] = -1
 */

#include <vector>

class Solution {
public:
    int minDifficulty(std::vector<int> &jobDifficulty, int d) {
        int n = static_cast<int>(jobDifficulty.size());
        std::vector<int> dp(n + 1, -1), dp_1(n + 1, -1);

        // j = 0
        dp_1[n] = 0;

        for (int j = 1; j <= d; ++j) {
            dp[n] = -1;
            for (int i = 0; i < n; ++i) {
                int max_diff = -1, today_diff = INT32_MAX;
                for (int k = 1; k <= n - i; ++k) {
                    max_diff = std::max(max_diff, jobDifficulty[i + k - 1]);
                    if (dp_1[i + k] != -1) {
                        today_diff = std::min(today_diff, dp_1[i + k] + max_diff);
                    }
                }
                dp[i] = (today_diff == INT32_MAX ? -1 : today_diff);
            }
            std::swap(dp, dp_1);
        }

        return dp_1[0];
    }
};

#endif //LEETCODE_1335_2_H
