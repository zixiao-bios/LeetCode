#ifndef LEETCODE_2404_H
#define LEETCODE_2404_H

#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;

class Solution {
public:
    int mostFrequentEven(vector<int> &nums) {
        std::unordered_map<int, int> count;
        for (const auto &each: nums) {
            if (each % 2 == 0) {
                ++count[each];
            }
        }

        int ans = -1, max_num = 0;
        for (const auto &each: count) {
            if (each.second > max_num or (each.second == max_num and each.first < ans)) {
                ans = each.first;
                max_num = each.second;
            }
        }
        return ans;
    }
};

#endif //LEETCODE_2404_H
