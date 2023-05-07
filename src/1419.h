#ifndef LEETCODE_1419_H
#define LEETCODE_1419_H

/**
 * 用一个 map 记录叫到某个字母的青蛙的个数，即 map['r'] 表示已经叫了 'c'，应该叫 'r' 的青蛙个数。
 *
 * 用 tot_num 记录所有需要的青蛙个数，rest_num 表示已经叫完的青蛙个数
 * 遍历字符串，如果为 'c' 说明需要新的青蛙叫一声，则 ++map['r']，--rest_num or ++tot_num
 * 如果为 'r' 'o' 'a'，此时若 map 中有对应的元素，说明已经有青蛙该叫这一声，则该元素 -1，下一个元素 +1；若没有，则说明不是有效组合
 * 如果为 'k'，若 map 中有 'k'，则该元素 -1，++rest_num
 */

#include <unordered_map>

class Solution {
public:
    int tot_frog = 0, rest_frog = 0;
    std::unordered_map<char, char> next_char = {{'c', 'r'},
                                                {'r', 'o'},
                                                {'o', 'a'},
                                                {'a', 'k'}};

    int minNumberOfFrogs(std::string croakOfFrogs) {
        std::unordered_map<char, int> count;
        for (const auto &ch: croakOfFrogs) {
            if (ch == 'c') {
                // 第一声
                need_frog();
                ++count[next_char[ch]];
            } else if (count.find(ch) == count.end() or count[ch] == 0) {
                // 没有匹配的
                return -1;
            } else {
                // 有匹配的，继续叫
                --count[ch];
                if (ch == 'k') {
                    ++rest_frog;
                } else {
                    ++count[next_char[ch]];
                }
            }
        }

        for (const auto &each: count) {
            if (each.second != 0) {
                return -1;
            }
        }
        return tot_frog;
    }

    void need_frog() {
        if (rest_frog == 0) {
            ++tot_frog;
        } else {
            --rest_frog;
        }
    }
};

#endif //LEETCODE_1419_H
