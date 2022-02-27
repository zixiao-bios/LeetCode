#ifndef LEETCODE_0977_H
#define LEETCODE_0977_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int pos = j;
        vector<int> ans(nums.size());

        while (i <= j) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                ans[pos] = nums[j] * nums[j];
                --j;
            } else {
                ans[pos] = nums[i] * nums[i];
                ++i;
            }
            --pos;
        }

        return ans;
    }
};

#endif //LEETCODE_0977_H
