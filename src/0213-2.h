#ifndef LEETCODE_0213_2_H
#define LEETCODE_0213_2_H

#include <vector>

using namespace std;

/**
 * dp[i]: 偷窃前 i 个房屋的最大收益
 */

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() <= 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }

        return max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
    }

    int robRange(vector<int> &nums, int start, int end) {
        int n = end - start + 1;

        if (n <= 0) {
            return 0;
        } else if (n == 1) {
            return nums[start];
        } else if (n == 2) {
            return max(nums[start], nums[start + 1]);
        }

        vector<int> dp(3, -1);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 3; i < n + 1; ++i) {
            dp[2] = max(dp[1], dp[0] + nums[start + i - 1]);

            swap(dp[0], dp[1]);
            swap(dp[1], dp[2]);
        }

        return dp[1];
    }
};

#endif //LEETCODE_0213_2_H
