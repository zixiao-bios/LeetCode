#ifndef LEETCODE_1144_H
#define LEETCODE_1144_H

#include <vector>

using namespace std;

class Solution {
public:
    // 在不越界的前提下，获取 nums 中 i 索引两侧的最小元素
    static int get_min(const vector<int> &nums, int i) {
        if (i == 0) {
            return nums[1];
        } else if (i == nums.size() - 1) {
            return nums[i - 1];
        } else {
            return min(nums[i - 1], nums[i + 1]);
        }
    }

    int movesToMakeZigzag(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }

        vector n(2, 0);     // n[0]代表偶数位置小于两侧的情况，n[1]代表奇数位置小于两侧的情况
        for (int i = 0; i < nums.size(); ++i) {
            int t = get_min(nums, i);
            if (t <= nums[i]) {
                n[i % 2] += nums[i] - t + 1;
            }
        }
        return min(n[0], n[1]);
    }
};

#endif //LEETCODE_1144_H
