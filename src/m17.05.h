#ifndef LEETCODE_M17_05_H
#define LEETCODE_M17_05_H

#include <vector>
#include <unordered_map>

using std::vector, std::string;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string> &array) {
        int n = array.size();
        vector prefix_sum(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + to_value(array[i - 1]);
        }

        // 题目转化为在prefix_sum找到a和b，满足b-a==0，且尽可能相距更远
        std::unordered_map<int, int> map{};
        int len = 0, begin, end;
        for (int i = 0; i < n + 1; ++i) {
            if (map.find(prefix_sum[i]) != map.end()) {
                if (i - map[prefix_sum[i]] > len) {
                    len = i - map[prefix_sum[i]];
                    begin = map[prefix_sum[i]];
                    end = i;
                }
            } else {
                map[prefix_sum[i]] = i;
            }
        }

        if (len > 0) {
            return {array.begin() + begin, array.begin() + end};
        } else {
            return {};
        }
    }

    int to_value(const string &s) {
        if (s[0] >= '0' and s[0] <= '9') {
            return 1;
        } else {
            return -1;
        }
    }
};

#endif //LEETCODE_M17_05_H
