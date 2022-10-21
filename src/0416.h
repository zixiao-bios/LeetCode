#ifndef LEETCODE_0416_H
#define LEETCODE_0416_H

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * dp[i][j]: 在前 i 个数中，能否选出和为 j 的一些数
 *
 * if (j >= num[i-1])
 *      dp[i][j] = dp[i-1][j] or dp[i-1][j-num[i-1]]
 * else
 *      dp[i][j] = dp[i-1][j]
 *
 * dp[0][0] = true, dp[0][j] = false
 */

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        if (nums.size() < 2) {
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        int n = nums.size();
        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for (int i = 1; i < n + 1; ++i) {
            for (int j = target; j >= nums[i - 1]; --j) {
                dp[j] = dp[j] or dp[j - nums[i - 1]];
            }
        }

        return dp[target];
    }
};

#endif //LEETCODE_0416_H
