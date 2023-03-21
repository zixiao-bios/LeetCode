#ifndef LEETCODE_1012_H
#define LEETCODE_1012_H

#include <vector>

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        s_ = std::to_string(n);
        mem = std::vector(s_.size(), std::vector(1 << 10, -1));
        return n - find_num(0, 0, false, true);
    }

    /// 返回 [1, x] 中，不含重复数字的数的个数
    /// \param level s 的 [level, end) 子串表示的数字为 x
    /// \param used 0-9 中已经用过的数字，即若 used 的第 n 位为 1，表示数字 n 用过，则数字中不能再包含 n
    /// \param is_num 上一位是否填充了数字，若否，则当前位也可以不填数字
    /// \param is_limited 第 level 位是否受到 n 的限制
    /// \return
    int find_num(int level, int used, bool is_num, bool limited) {
        if (level == s_.size()) {
            return is_num;
        }

        if (mem[level][used] != -1 and is_num and !limited) {
            return mem[level][used];
        }

        int res = 0;
        if (!is_num) {
            res += find_num(level + 1, used, false, false);
        }

        int up = limited ? s_[level] - '0' : 9;
        for (int i = !is_num; i <= up; ++i) {
            if ((1 << i) & used) {
                // 数字 i 用过了
                continue;
            }
            res += find_num(level + 1, (1 << i) | used, true, limited and i == up);
        }

        if (is_num and !limited) {
            mem[level][used] = res;
        }
        return res;
    }

private:
    std::string s_;

    // mem[level][used] 为函数 find_num(level, used, true, false)的结果
    std::vector<std::vector<int>> mem;
};

#endif //LEETCODE_1012_H
