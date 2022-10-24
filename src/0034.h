#ifndef LEETCODE_0034_H
#define LEETCODE_0034_H

#include <vector>

using namespace std;

class Solution {
public:
    int find(const vector<int> &nums, int target, int start, int end, char direction) {
        if (start > end) {
            return -1;
        }

        int mid = (start + end) / 2;

        switch (direction) {
            case 'r':
                if (nums[mid] == target and (mid == nums.size() - 1 or nums[mid + 1] != target)) {
                    return mid;
                } else if (nums[mid] <= target) {
                    return find(nums, target, mid + 1, end, direction);
                } else {
                    return find(nums, target, start, mid - 1, direction);
                }
            case 'l':
                if (nums[mid] == target and (mid == 0 or nums[mid - 1] != target)) {
                    return mid;
                } else if (nums[mid] < target) {
                    return find(nums, target, mid + 1, end, direction);
                } else {
                    return find(nums, target, start, mid - 1, direction);
                }
            default:
                return -1;
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {find(nums, target, 0, nums.size() - 1, 'l'), find(nums, target, 0, nums.size() - 1, 'r')};
    }
};

#endif //LEETCODE_0034_H
