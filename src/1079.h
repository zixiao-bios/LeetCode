#ifndef LEETCODE_1079_H
#define LEETCODE_1079_H

#include <unordered_map>

class Solution {
public:
    std::unordered_map<char, int> count;

    int numTilePossibilities(std::string tiles) {
        for (const auto &ch: tiles) {
            ++count[ch];
        }

        int ans = 0;
        for (int i = 1; i <= tiles.size(); ++i) {
            ans += backtrace(0, i);
        }
        return ans;
    }

    int backtrace(int level, int len) {
        if (level == len) {
            return 1;
        }

        int n = 0;
        for (auto &tile: count) {
            if (tile.second > 0) {
                --tile.second;
                n += backtrace(level + 1, len);
                ++tile.second;
            }
        }
        return n;
    }
};

#endif //LEETCODE_1079_H
