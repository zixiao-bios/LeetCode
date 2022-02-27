#ifndef LEETCODE_0413_H
#define LEETCODE_0413_H

#include <vector>

using namespace std;

/**
 * dp[i]: num[0] ~ num[i] 中以 num[i] 结尾的等差子数组个数
 *
 * 递推: if(num[i] - num[i-1] == num[i-1] - num[i-2])
 *          dp[i] = dp[i-1] + 1
 *      else
 *          dp[i] = 0
 *
 * 边界: dp[0] = dp[1] = 0
 */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }

        int ans = 0, dp = 0;

        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                ++dp;
            } else {
                dp = 0;
            }

            ans += dp;
        }

        return ans;
    }
};

#endif //LEETCODE_0413_H
