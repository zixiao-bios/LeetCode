#ifndef LEETCODE_2451_H
#define LEETCODE_2451_H

#include <vector>

class Solution {
public:
    std::string oddString(std::vector<std::string> &words) {
        auto n = words.size();
        if (n == 2) {
            return words[0];
        }

        // n >= 3
        auto a1 = get_int_array(words[0]);
        auto a2 = get_int_array(words[1]);
        auto a3 = get_int_array(words[2]);
        std::vector<int> target;
        if (a1 == a2) {
            target = a1;
        } else {
            if (a1 == a3) {
                target = a1;
            } else {
                target = a2;
            }
        }

        for (const auto &word: words) {
            if (get_int_array(word) != target) {
                return word;
            }
        }
        return "";
    }

    std::vector<int> get_int_array(const std::string &s) {
        std::vector<int> res;
        res.reserve(s.size() - 1);
        for (int i = 0; i < s.size() - 1; ++i) {
            res.push_back(s[i + 1] - s[i]);
        }
        return res;
    }
};

#endif //LEETCODE_2451_H
