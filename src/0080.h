#ifndef LEETCODE_0080_H
#define LEETCODE_0080_H

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int left = 0, right = 0;
        int num = nums[0] + 1, count = 0;
        bool save;
        while (right < nums.size()) {
            if (nums[right] == num) {
                ++count;
                if (count > 2) {
                    ++right;
                    save = false;
                } else {
                    save = true;
                }
            } else {
                num = nums[right];
                count = 1;
                save = true;
            }

            if (save) {
                nums[left] = nums[right];
                ++left, ++right;
            }
        }

        return left;
    }
};

#endif //LEETCODE_0080_H
