#ifndef LEETCODE_982_H
#define LEETCODE_982_H

#include <vector>
#include <cmath>

using std::vector;

class Solution {
public:
    int ans{0};

    int countTriplets(vector<int> &nums) {
        backtrace(nums, 1, 0);
        return ans;
    }

    void backtrace(const vector<int> &nums, int res, int level) {
        if (res == 0) {
            ans += int(std::round(pow(nums.size(), 3 - level)));
            return;
        }

        if (level == 3) {
            return;
        }

        if (level == 0) {
            for (auto &each: nums) {
                backtrace(nums, each, 1);
            }
        } else {
            for (auto &each: nums) {
                backtrace(nums, each & res, level + 1);
            }
        }
    }
};

#endif //LEETCODE_982_H
