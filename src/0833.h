#ifndef LEETCODE_0833_H
#define LEETCODE_0833_H

#include <vector>
#include <tuple>
#include <algorithm>

using std::string, std::vector;
using option_t = std::tuple<int, string, string>;

class Solution {
public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets) {
        vector<option_t> options;
        options.reserve(indices.size());
        for (int i = 0; i < indices.size(); ++i) {
            options.emplace_back(indices[i], sources[i], targets[i]);
        }

        std::sort(options.begin(), options.end(), [](const option_t &a, const option_t &b) {
            return std::get<0>(a) < std::get<0>(b);
        });

        string ans;
        size_t p = 0;  // 字符串中，当前待录入的第一个字符位置
        for (const auto &option: options) {
            const int &idx = std::get<0>(option);
            const string &source = std::get<1>(option), &target = std::get<2>(option);

            if (p < idx) {
                // 这一段不需要变化，先复制过去
                ans += s.substr(p, idx - p);
                p = idx;
            }

            if (s.substr(idx, source.size()) == source) {
                // 字符串匹配，开始替换
                ans += target;
                p += source.size();
            }
        }
        ans += s.substr(p);
        return ans;
    }
};

#endif //LEETCODE_0833_H
