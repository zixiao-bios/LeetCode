#ifndef LEETCODE_2460_H
#define LEETCODE_2460_H

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        auto n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int rear = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                std::swap(nums[rear], nums[i]);
                ++rear;
            }
        }
        return nums;
    }
};

#endif //LEETCODE_2460_H
