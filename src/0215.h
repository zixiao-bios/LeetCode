#ifndef LEETCODE_0215_H
#define LEETCODE_0215_H

#include <vector>
#include <random>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int l = 0, r = nums.size() - 1, index;

        while (l <= r) {
            index = quickSelection(nums, l, r);

            if (index + 1 == k) {
                return nums[index];
            } else if (index + 1 > k) {
                r = index - 1;
            } else {
                l = index + 1;
            }
        }

        return -1;
    }

    int quickSelection(vector<int> &nums, int start, int end) {
        swap(nums[start], nums[(rand() % (end - start + 1)) + start]);

        int l = start, r = end, key = nums[start];

        while (l < r) {
            while (l < r and nums[r] <= key) {
                --r;
            }
            nums[l] = nums[r];

            while (l < r and nums[l] >= key) {
                ++l;
            }
            nums[r] = nums[l];
        }

        nums[r] = key;
        return r;
    }
};

#endif //LEETCODE_0215_H
