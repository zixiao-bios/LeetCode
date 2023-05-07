#ifndef LEETCODE_1048_H
#define LEETCODE_1048_H

#include <vector>

using std::vector, std::string;

class Solution {
public:
    int max_len = 16;

    // {str, n}，表示以 str 开头的字符串链的最大长度为 n
    using s_data = std::pair<string, int>;
    using s_data_list = vector<s_data>;

    int longestStrChain(vector<string> &words) {
        vector<s_data_list> data(max_len + 1);
        for (const auto &word: words) {
            data[word.size()].emplace_back(word, 1);
        }

        int ans = 1;
        for (int i = max_len - 1; i > 0; --i) {
            for (auto &s_data: data[i]) {
                int res = 1;
                for (const auto &target_s_data: data[i + 1]) {
                    if (is_pre(s_data.first, target_s_data.first)) {
                        res = std::max(res, target_s_data.second + 1);
                    }
                }
                s_data.second = res;
                ans = std::max(ans, res);
            }
        }
        return ans;
    }

    bool is_pre(const string &pre, const string &s) {
        if (pre.size() + 1 != s.size()) {
            return false;
        }

        bool inserted = false;
        for (int i_pre = 0, i_s = 0; i_pre < pre.size();) {
            if (pre[i_pre] != s[i_s]) {
                if (inserted) {
                    return false;
                } else {
                    inserted = true;
                    ++i_s;
                }
            } else {
                ++i_pre;
                ++i_s;
            }
        }
        return true;
    }
};

#endif //LEETCODE_1048_H
