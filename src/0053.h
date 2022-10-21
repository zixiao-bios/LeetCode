#ifndef LEETCODE_0053_H
#define LEETCODE_0053_H

#include <vector>

using namespace std;

/**
 * dp[i]: 以 nums[i] 结尾的子数组的最大和
 */

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> dp(2, -1);
        dp[0] = nums[0];

        int ans = dp[0];

        for (int i = 1; i < nums.size(); ++i) {
            dp[1] = max(dp[0] + nums[i], nums[i]);

            swap(dp[0], dp[1]);
            ans = max(ans, dp[0]);
        }

        return ans;
    }
};

#endif //LEETCODE_0053_H
