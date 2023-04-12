#ifndef LEETCODE_1147_H
#define LEETCODE_1147_H

class Solution {
public:
    int longestDecomposition(std::string text) {
        int ans = 0, t = 1;
        auto start = text.begin(), end = text.end();
        while (t != 0) {
            t = remove_pair(start, end);
            ans += t;
        }
        return ans;
    }

    /// 从字符串中删去两头的最小重复子串，更新迭代器使其指向删除字串后中间剩余的字符串，并返回删除的子串数量
    /// 如果字符串长度为 0，返回 0
    /// 如果在字符串两头找到了重复子串，返回 2，并移动迭代器删除这两段最小重复子串
    /// 如果未找到重复子串，返回 1，并移动迭代器删除该字符串（长度为 0）
    int remove_pair(std::string::iterator &start, std::string::iterator &end) {
        if (start >= end) {
            return 0;
        }
        auto mid = start + (end + 1 - start) / 2;
        auto right_start = end - 1;
        while (mid <= right_start and !is_hw(start, right_start, end)) {
            --right_start;
        }
        start += end - right_start;
        end = right_start;
        return (right_start >= mid) + 1;
    }

    bool is_hw(const std::string::iterator &prefix,
               const std::string::iterator &target_start, const std::string::iterator &target_end) {
        for (auto target_p = target_start, prefix_p = prefix; target_p != target_end; ++target_p, ++prefix_p) {
            if (*target_p != *prefix_p) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODE_1147_H
