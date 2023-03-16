#ifndef LEETCODE_2488_H
#define LEETCODE_2488_H

/**
 * 子数组一定包含 k。
 * 若子数组长度为奇数，则子数组中小于k和大于k的元素数量相等。
 * 假设 k 左侧小于和大于k的元素个数分别为 l_small 和 l_large，右侧为 r_small 和 r_large
 * 则有 l_small + r_small == l_large + r_large
 * 得到 l_small - l_large == r_large - r_small
 *
 * 将原始数组分割为三部分：k左侧，k，k右侧
 * 对k左侧部分，大于k的元素记为-1，小于k的元素记为1；k右侧部分反之。
 * 则问题转化为，取k左侧部分的后缀，以及k右侧部分的前缀，使得该后缀==该前缀，有多少种取法。
 * 可使用哈希表在O(n)时间下求解。
 *
 * 若子数组长度为偶数，则关系式变为：l_small + r_small + 1 == l_large + r_large
 * 即 l_small - l_large == r_large - r_small - 1
 * 匹配哈希表时，同时匹配上述两式的值即可。
 */

#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
    int countSubarrays(vector<int> &nums, int k) {
        auto n = nums.size();
        int idx_k;
        vector<int> val(n);

        // 将nums中元素转换为 1 或 -1
        bool left = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == k) {
                idx_k = i;
                left = false;
                val[i] = 0;
                continue;
            }

            val[i] = 2 * ((left and nums[i] < k) + (!left and nums[i] > k)) - 1;
        }

        // 求k左侧部分的后缀和，存入哈希表
        std::unordered_map<int, int> cnt;
        int suffix = 0;
        for (int i = idx_k; i >= 0; --i) {
            suffix += val[i];
            ++cnt[suffix];
        }

        // 求k右侧部分的前缀和，并在哈希表里寻找符合的后缀和，同时考虑奇数和偶数情况
        int ans = 0, prefix = 0;
        for (int i = idx_k; i < n; ++i) {
            prefix += val[i];
            ans += cnt[prefix];
            ans += cnt[prefix - 1];
        }

        return ans;
    }
};

#endif //LEETCODE_2488_H
