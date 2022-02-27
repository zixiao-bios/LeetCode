#ifndef LEETCODE_0213_H
#define LEETCODE_0213_H

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        return max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
    }

    int robRange(vector<int> &nums, int start, int end) {
        int a = nums[start];
        int b = max(nums[start], nums[start + 1]);
        int c;

        for (int i = start + 2; i <= end; ++i) {
            c = max(a + nums[i], b);
            a = b;
            b = c;
        }

        return b;
    }
};

#endif //LEETCODE_0213_H
