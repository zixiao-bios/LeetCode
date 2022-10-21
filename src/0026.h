#ifndef LEETCODE_0026_H
#define LEETCODE_0026_H

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        // start: 值为 value 的首个元素的索引
        // end: 下一个值不同的首个元素的索引
        int start = 0, end = 0;

        while (end < nums.size()) {
            if (nums[start] == nums[end]) {
                ++end;
            } else {
                nums[++start] = nums[end];
            }
        }

        return start + 1;
    }
};

#endif //LEETCODE_0026_H
