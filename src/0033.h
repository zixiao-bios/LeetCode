#ifndef LEETCODE_0033_H
#define LEETCODE_0033_H

#include <vector>

using namespace std;

class Solution {
public:
    int find(const vector<int>& nums, int target, int start, int end) {
        if (start > end) {
            return -1;
        }

        int mid = (start + end) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[start] <= nums[mid]) {
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

    int search(vector<int>& nums, int target) {
        return find(nums, target, 0, nums.size() - 1);
    }
};

#endif //LEETCODE_0033_H
