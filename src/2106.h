#ifndef LEETCODE_2106_H
#define LEETCODE_2106_H

/**
 * 最终走过的区域，是一个包含 startPos 的连续区间
 * 显然最多只变换一次方向，即先向左走，再掉头向右走
 *
 * 假设向左走到 fruits[left][0]，向右走到 fruits[right][0]，左右区间长度分别为 left_len 和 right_len
 * 则需要满足 left_len * 2 + right_len <= k
 * 使用双指针法枚举即可，时间复杂度为 O(k)
 */

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
        auto n = fruits.size();
        // left 为向左能拿到的最远水果
        // 有几种情况：
        // 1. 从左侧拿不到水果，且右侧没有水果，此时 left == n
        // 2. 从左侧拿不到水果，但右侧有水果，此时 left 指向右侧第一个水果
        int left = static_cast<int>(std::lower_bound(fruits.begin(), fruits.end(), startPos - k,
                                                     [](const vector<int> &a, int target) {
                                                         return a[0] < target;
                                                     }) - fruits.begin());

        int sum = 0, ans = 0;
        for (int right = left; right < n and fruits[right][0] <= startPos + k; ++right) {
            sum += fruits[right][1];
            while (startPos - fruits[left][0] + fruits[right][0] - fruits[left][0] > k and
                   fruits[right][0] - startPos + fruits[right][0] - fruits[left][0] > k) {
                sum -= fruits[left][1];
                ++left;
            }
            ans = std::max(ans, sum);
        }
        return ans;
    }
};

#endif //LEETCODE_2106_H
