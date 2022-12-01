#ifndef LEETCODE_0198_H
#define LEETCODE_0198_H

/**
 * dp[i]:只考虑到索引为 i 的房子，能抢劫的最大金额
 *
 * dp[i] = max(dp[i-1], dp[i-2] + val[i])
 *
 * dp[0] = val[0]
 * dp[1] = max(val[0], val[1])
 */

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        int di_1 = max(nums[0], nums[1]);
        int di_2 = nums[0];
        int di = di_1;

        for (int i = 2; i < n; ++i) {
            di = max(di_1, di_2 + nums[i]);
            di_2 = di_1;
            di_1 = di;
        }

        return di;
    }
};

#endif //LEETCODE_0198_H
