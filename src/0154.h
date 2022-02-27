#ifndef LEETCODE_0154_H
#define LEETCODE_0154_H

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid, min = INT_MAX;

        while (l <= r) {
            mid = l + ((r - l) >> 1);

            if (nums[mid] == nums[l] and nums[mid] == nums[r]) {
                // 无法判断递增情况
                min = std::min(min, nums[mid]);
                ++l, --r;
            } else if (nums[mid] >= nums[l]) {
                // 左边是递增的
                min = std::min(min, nums[l]);
                l = mid + 1;
            } else {
                // 右边是递增的
                min = std::min(min, nums[mid]);
                r = mid - 1;
            }
        }

        return min;
    }
};

#endif //LEETCODE_0154_H
