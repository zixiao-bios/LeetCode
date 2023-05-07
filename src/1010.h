#ifndef LEETCODE_1010_H
#define LEETCODE_1010_H

/**
 * time 的范围是 [1, 500]，因此歌曲对的时长范围为 [2, 1000]
 * 即可能的情况只有 60, 120, 180, 240, 300, 360 等有限种情况
 *
 * 遍历 time，使用一个 map 记录已遍历到的该时长的歌曲数
 * 对每一个新遍历到的歌曲，取每种可能的歌曲对时长与之相减，检查相减后的结果是否在 map 中
 */

#include <vector>
#include <unordered_map>

class Solution {
public:
    int numPairsDivisibleBy60(std::vector<int> &time) {
        std::vector<int> targets;
        for (int i = 1; i * 60 <= 1000; ++i) {
            targets.push_back(i * 60);
        }

        std::unordered_map<int, int> count;
        int ans = 0;

        for (const auto &each: time) {
            for (const auto &target: targets) {
                if (count.find(target - each) != count.end()) {
                    ans += count[target - each];
                }
            }
            ++count[each];
        }
        return ans;
    }
};

#endif //LEETCODE_1010_H
