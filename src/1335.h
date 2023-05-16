#ifndef LEETCODE_1335_H
#define LEETCODE_1335_H

/**
 * dp[i][j]: 从索引为 i 的工作开始，制定 j 天的计划表，工作计划的最低难度值
 *
 * 假设第一天完成的任务数为 k
 * dp[i][j] = min( dp[i+k][j-1] + max(jobDiff[i:i+k)) )     , 1 <= k <= n-i
 */

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> min_diff;
    int n;

    int minDifficulty(std::vector<int> &jobDifficulty, int d) {
        n = static_cast<int>(jobDifficulty.size());
        min_diff = std::vector(n + 1, std::vector(d + 1, -1));
        return get_min_diff(jobDifficulty, 0, d);
    }

    int get_min_diff(const std::vector<int> &job_diff, int i, int j) {
        if (min_diff[i][j] != -1) {
            return min_diff[i][j];
        }

        if (j == 0) {
            return i == n ? 0 : -1;
        }

        int max_diff = -1, today_diff = INT32_MAX;
        for (int k = 1; k <= n - i; ++k) {
            max_diff = std::max(max_diff, job_diff[i + k - 1]);
            int t = get_min_diff(job_diff, i + k, j - 1);
            if (t != -1) {
                today_diff = std::min(max_diff + t, today_diff);
            }
        }

        if (today_diff != INT32_MAX) {
            min_diff[i][j] = today_diff;
        }
        return min_diff[i][j];
    }
};

#endif //LEETCODE_1335_H
