#ifndef LEETCODE_1031_2_H
#define LEETCODE_1031_2_H

#include <vector>

using std::vector;

class Solution {
public:
    int n;
    vector<int> prefix_sum;

    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
        n = static_cast<int>(nums.size());
        prefix_sum = vector<int>(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }

        return std::max(max_two_sub_sum(nums, firstLen, secondLen),
                        max_two_sub_sum(nums, secondLen, firstLen));
    }

    int max_two_sub_sum(const vector<int> &nums, int left_len, int right_len) {
        int max_l_sum = 0, ans = 0;
        for (int r_begin = left_len; r_begin + right_len <= n; ++r_begin) {
            int l_begin = r_begin - left_len;
            max_l_sum = std::max(max_l_sum, prefix_sum[l_begin + left_len] - prefix_sum[l_begin]);
            ans = std::max(ans, max_l_sum + prefix_sum[r_begin + right_len] - prefix_sum[r_begin]);
        }
        return ans;
    }
};

#endif //LEETCODE_1031_2_H
