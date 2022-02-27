#ifndef LEETCODE_0076_H
#define LEETCODE_0076_H

#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> origin, count;

    string minWindow(string s, string t) {

        for (auto &ch: t) {
            ++origin[ch];
        }

        int r = 0, l = 0, len = INT_MAX, ansL = -1;

        while (r < s.size()) {
            // 统计窗口中包括的字符
            if (origin[s[r]] > 0) {
                ++count[s[r]];
            }

            // 尝试缩小窗口
            while (l <= r and check()) {
                if (r - l + 1 < len) {
                    // 找到了更小的答案，记录下来
                    len = r - l + 1;
                    ansL = l;
                }

                // 缩小窗口（右移l）
                if (origin[s[l]] > 0) {
                    --count[s[l]];
                }
                ++l;
            }

            // 扩大窗口
            ++r;
        }

        if (ansL == -1) {
            return "";
        } else {
            return s.substr(ansL, len);
        }
    }

    bool check() {
        for (const auto &c: origin) {
            if (count[c.first] < c.second) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODE_0076_H
