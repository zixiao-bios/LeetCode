#ifndef LEETCODE_0540_H
#define LEETCODE_0540_H

#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums[nums.size() - 2] != nums[nums.size() - 1]) {
            return nums[nums.size() - 1];
        }

        int l = 0, r = nums.size() - 3, mid, ans;

        while (l <= r) {
            mid = l + ((r - l) >> 1);

            // 把mid变为偶数
            if (mid % 2 != 0) {
                --mid;
            }

            if (nums[mid] == nums[mid + 1]) {
                // 答案在右侧
                l = mid + 2;
            } else {
                // 答案在当前，或者左侧
                ans = mid;
                r = mid - 2;
            }
        }

        return nums[ans];
    }
};

#endif //LEETCODE_0540_H
