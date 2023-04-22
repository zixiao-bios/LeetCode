#ifndef LEETCODE_1027_H
#define LEETCODE_1027_H

/**
 * dp[i][j]: 以 nums[i] 结尾的公差为 j 的等差子序列的最大长度
 *
 * dp[i][j] = dp[k][j] + 1      , 0 <= k < i, j = nums[i] - nums[k]
 *
 * if dp[k][j] not exists, dp[k][j] = 1
 */

#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
    int longestArithSeqLength(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        vector<std::unordered_map<int, int>> dp(n);
        int ans = 0;

        for (int i = 1; i < n; ++i) {
            for (int k = 0; k < i; ++k) {
                int d = nums[i] - nums[k];
                if (dp[k].find(d) == dp[k].end()) {
                    dp[i][d] = 2;
                } else {
                    dp[i][d] = dp[k][d] + 1;
                }
                ans = std::max(ans, dp[i][d]);
            }
        }

        return ans;
    }
};

#endif //LEETCODE_1027_H
