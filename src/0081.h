#ifndef LEETCODE_0081_H
#define LEETCODE_0081_H

#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return false;
        }

        int l = 0, r = nums.size() - 1, mid;

        while (l <= r) {
            mid = l + ((r - l) >> 1);

            if (nums[mid] == target) {
                return true;
            }

            if (nums[mid] == nums[l] and nums[mid] == nums[r]) {
                ++l, --r;
            } else if (nums[mid] >= nums[l]) {
                // 左侧是递增的
                if (nums[mid] > target and nums[l] <= target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // 右侧是递增的
                if (nums[mid] < target and nums[r] >= target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return false;
    }
};

#endif //LEETCODE_0081_H
