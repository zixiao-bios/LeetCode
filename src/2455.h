#ifndef LEETCODE_2455_H
#define LEETCODE_2455_H

#include <vector>

class Solution {
public:
    int averageValue(std::vector<int> &nums) {
        int sum = 0, n = 0;
        for (const auto &each: nums) {
            if (each % 6 == 0) {
                sum += each;
                ++n;
            }
        }
        if (sum == 0) {
            return 0;
        } else {
            return sum / n;
        }
    }
};

#endif //LEETCODE_2455_H
