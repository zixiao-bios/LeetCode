#ifndef LEETCODE_0169_H
#define LEETCODE_0169_H

#include <vector>

using std::vector;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int count = 0, target = 0;
        for (const auto &each: nums) {
            if (each == target) {
                ++count;
            } else {
                if (count == 0) {
                    target = each;
                    count = 1;
                } else {
                    --count;
                }
            }
        }
        return target;
    }
};

#endif //LEETCODE_0169_H
