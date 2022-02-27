#ifndef LEETCODE_0034_H
#define LEETCODE_0034_H

#include <vector>

using namespace std;

class Solution {
public:
    int find(vector<int> &nums, int target, bool lower) {
        int l = 0, r = nums.size() - 1, mid;

        while (l <= r) {
            mid = l + ((r - l) >> 2);

            if (nums[mid] > target or (lower and nums[mid] == target)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return lower ? r + 1 : r;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }

        int l = find(nums, target, true);
        int r = find(nums, target, false);

        if (l >= nums.size() or r>= nums.size() or nums[l] != target) {
            return {-1, -1};
        } else {
            return {l, r};
        }
    }
};

#endif //LEETCODE_0034_H
