#ifndef LEETCODE_1043_2_H
#define LEETCODE_1043_2_H

/**
 * dp[i]：只考虑 arr 的前 i 个元素的答案值
 *
 * 设末尾子数组为 end_arr ，其长度为 j，索引范围为 [i-j, i-1]
 * dp[i] = max( dp[i-j] + max(end_arr) * j )  , 1 <= j <= min(k, i)
 *
 * dp[1] = arr[0]
 */

#include <vector>

using std::vector;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i < n + 1; ++i) {
            int max_ele = -1;
            for (int j = 1; j <= std::min(k, i); ++j) {
                max_ele = std::max(max_ele, arr[i - j]);
                dp[i] = std::max(dp[i], dp[i - j] + max_ele * j);
            }
        }
        return dp[n];
    }
};

#endif //LEETCODE_1043_2_H
