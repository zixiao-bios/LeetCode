#ifndef LEETCODE_0198_H
#define LEETCODE_0198_H

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /// value[i] = max(value[i-2] + nums[i], value[i-1])
        /// value[0] = nums[0], value[1] = max(nums[0], nums[1])
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> value(3);
        value[0] = nums[0];
        value[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            value[2] = max(value[0] + nums[i], value[1]);
            value[0] = value[1];
            value[1] = value[2];
        }

        return value[2];
    }
};

#endif //LEETCODE_0198_H
