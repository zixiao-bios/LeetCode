#ifndef LEETCODE_0540_H
#define LEETCODE_0540_H

#include <vector>

using namespace std;

class Solution {
public:
    int relative_x(const vector<int>& nums, int i) {
        if (i == 0) {
            return nums[i] == nums[i + 1] ? -1 : 0;
        }

        if (i == nums.size() - 1) {
            return nums[i] == nums[i - 1] ? 1 : 0;
        }

        if (nums[i] != nums[i - 1] and nums[i] != nums[i + 1]) {
            return 0;
        } else if (nums[i] == nums[i - 1]) {
            return i % 2 == 0 ? 1 : -1;
        } else {
            return i % 2 == 0 ? -1 : 1;
        }
    }

    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            switch (relative_x(nums, mid)) {
                case 0:
                    return nums[mid];
                case -1:
                    l = mid + 1;
                    break;
                case 1:
                    r = mid - 1;
            }
        }

        return 666;
    }
};

#endif //LEETCODE_0540_H
