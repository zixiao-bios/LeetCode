#ifndef LEETCODE_0665_H
#define LEETCODE_0665_H

#include <vector>

using namespace std;

class Solution {
public:
    bool ok(const vector<int> &nums, int i) {
        if (i == 0) {
            return nums[i] <= nums[i + 1];
        }

        if (i == nums.size() - 1) {
            return nums[i] >= nums[i - 1];
        }

        return nums[i] >= nums[i - 1] and nums[i] <= nums[i + 1];
    }

    bool checkPossibility(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }

        bool has_changed = false;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                if (has_changed) {
                    return false;
                }

                int num_i = nums[i], num_i_1 = nums[i - 1];

                nums[i - 1] = num_i;
                if (ok(nums, i - 1)) {
                    has_changed = true;
                    continue;
                }

                nums[i - 1] = num_i_1;
                nums[i] = num_i_1;
                if (ok(nums, i)) {
                    has_changed = true;
                    continue;
                }

                return false;
            }
        }

        return true;
    }
};

#endif //LEETCODE_0665_H
