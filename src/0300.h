#ifndef LEETCODE_0300_H
#define LEETCODE_0300_H

#include <vector>

using namespace std;

/**
 * dp[i]: 以 nums[i] 结尾的最长子序列的长度
 *
 * dp[i] = max(dp[j] + 1), 0 <= j < i and nums[j] < nums[i]
 *
 * dp[0] = 1
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int max = 0;
        for (auto &each: dp) {
            max = std::max(max, each);
        }

        return max;
    }
};

#endif //LEETCODE_0300_H
