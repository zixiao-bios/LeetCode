#ifndef LEETCODE_0033_H
#define LEETCODE_0033_H

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;

        while (l <= r) {
            mid = l + ((r - l) >> 1);

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] >= nums[l]) {
                // 左侧是递增
                if (nums[mid] > target and nums[l] <= target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // 右侧是递增
                if (nums[mid] < target and nums[r] >= target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};

#endif //LEETCODE_0033_H
