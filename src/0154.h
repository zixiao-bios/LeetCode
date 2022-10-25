#ifndef LEETCODE_0154_H
#define LEETCODE_0154_H

#include <vector>

using namespace std;

class Solution {
public:
    int find(const vector<int> &nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }

        if (end - start == 1) {
            return min(nums[start], nums[end]);
        }

        int mid = (start + end) / 2;

        if (nums[start] == nums[mid]) {
            // 无法判断
            return min(nums[start], find(nums, start + 1, end));
        } else if (nums[start] < nums[mid]) {
            // 左侧为单增
            return min(nums[start], find(nums, mid + 1, end));
        } else {
            // 右侧为单增
            return min(nums[mid], find(nums, start, mid - 1));
        }
    }

    int findMin(vector<int>& nums) {
        return find(nums, 0, nums.size() - 1);
    }
};

#endif //LEETCODE_0154_H
