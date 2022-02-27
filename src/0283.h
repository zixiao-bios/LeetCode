#ifndef LEETCODE_0283_H
#define LEETCODE_0283_H

#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        int r = 0;

        while (r < nums.size()) {
            if (nums[r] != 0) {
                swap(nums[l], nums[r]);
                ++l;
            }
            ++r;
        }
    }
};

#endif //LEETCODE_0283_H
