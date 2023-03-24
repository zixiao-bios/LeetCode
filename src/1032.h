#ifndef LEETCODE_1032_H
#define LEETCODE_1032_H

#include <vector>
#include <unordered_set>

class StreamChecker {
public:
    int n;
    const std::vector<std::string> &words;

    // 对于每个words[i]，当前待匹配的索引集合为words_match[i]
    std::vector<std::unordered_set<int>> words_match;

    StreamChecker(std::vector<std::string> &words)
            : n(words.size()),
              words(words),
              words_match(std::vector<std::unordered_set<int>>(n, std::unordered_set<int>{})) {
    }

    bool query(char letter) {
        bool res = false;
        // 先检查已经匹配的words能否继续匹配下去
        for (int i = 0; i < n; ++i) {
            if (!words_match[i].empty()) {
                for (auto it = words_match[i].begin(); it != words_match[i].end();) {
                    int idx = *it;
                    it = words_match[i].erase(it);

                    if (idx == words[i].size()) {
                        // 匹配完成
                        res = true;
                    } else if (words[i][idx] == letter) {
                        // 匹配成功
                    } else {
                        // 匹配失败
                    }
                }
            }
        }

        return res;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

#endif //LEETCODE_1032_H
