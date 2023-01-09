#ifndef LEETCODE_0041_H
#define LEETCODE_0041_H

#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 答案一定在 [1, n+1] 中，用 nums 数组标记 [1, n] 中的数有没有出现过

        // 用负号标记出现过的数
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) - 1;
            if (idx >= 0 and idx < n) {
                nums[idx] = -abs(nums[idx]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

#endif //LEETCODE_0041_H
