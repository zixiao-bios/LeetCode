#ifndef LEETCODE_0918_H
#define LEETCODE_0918_H

/**
 * 对于没有跨越边界的子数组，用 dp 直接计算
 * 对于跨越边界的子数组，子数组之外的部分是没有跨越子数组的，可以反过来计算子数组最小和
 *
 * dp[i]: 以 nums[i] 结尾的子数组最大和
 *
 * dp[i] = max(nums[i], dp[i-1] + nums[i])
 */

#include <vector>
#include <functional>
#include <numeric>

using std::vector;

class Solution {
public:
    int get_sub_array_sum(const vector<int> &nums, const std::function<int(const int &, const int &)> &get) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = get(nums[i], dp[i - 1] + nums[i]);
            ans = get(ans, dp[i]);
        }
        return ans;
    }

    int maxSubarraySumCircular(vector<int> &nums) {
        int max_sum_1 = get_sub_array_sum(nums, [](const int &a, const int &b) { return a > b ? a : b; });
        int min_sum = get_sub_array_sum(nums, [](const int &a, const int &b) { return a < b ? a : b; });
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (min_sum == sum) {
            return max_sum_1;
        } else {
            return std::max(max_sum_1, sum - min_sum);
        }
    }
};

#endif //LEETCODE_0918_H
