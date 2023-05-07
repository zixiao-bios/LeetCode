#ifndef LEETCODE_1010_2_H
#define LEETCODE_1010_2_H

/**
 * 两个数求和能被 60 整除，等价于两个数对 60 取余后，相加等于 60
 * 使用数组 count，count[i] 表示取余后为 i 的元素的数量
 * 题目转化为《两数之和》
 */

#include <vector>
#include <unordered_map>

class Solution {
public:
    int numPairsDivisibleBy60(std::vector<int> &time) {
        std::vector<int> count(60, 0);
        int ans = 0;

        for (const auto &t: time) {
            ans += count[(60 - (t % 60)) % 60];
            ++count[t % 60];
        }
        return ans;
    }
};

#endif //LEETCODE_1010_2_H
