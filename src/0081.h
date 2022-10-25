#ifndef LEETCODE_0081_H
#define LEETCODE_0081_H

#include <vector>

using namespace std;

class Solution {
public:
    bool find(const vector<int> &nums, int target, int start, int end) {
        if (start > end) {
            return false;
        }

        int mid = (start + end) / 2;

        if (nums[mid] == target) {
            return true;
        }

        if (nums[start] == nums[mid]) {
            // 无法判断单调区间
            return find(nums, target, ++start, end);
        } else if (nums[start] < nums[mid]) {
            // 左侧为单调区间
            if (target >= nums[start] and target < nums[mid]) {
                return find(nums, target, start, mid - 1);
            } else {
                return find(nums, target, mid + 1, end);
            }
        } else {
            // 右侧为单调区间
            if (target > nums[mid] and target <= nums[end]) {
                return find(nums, target, mid + 1, end);
            } else {
                return find(nums, target, start, mid - 1);
            }
        }
    }

    bool search(vector<int>& nums, int target) {
        return find(nums, target, 0, nums.size() - 1);
    }
};

#endif //LEETCODE_0081_H
