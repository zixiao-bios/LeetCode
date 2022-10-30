#ifndef LEETCODE_0215_H
#define LEETCODE_0215_H

#include <vector>

using namespace std;

class Solution {
public:
    /// 在索引为 [start, end] 的区间中，返回一个元素的索引，且将数组修改为：该数左/右侧元素均小/大于该元素
    /// \param nums
    /// \param start
    /// \param end
    /// \return
    int select(vector<int> &nums, int start, int end) {
        int key = nums[start];
        int l = start, r = end;

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

        nums[l] = key;
        return l;
    }

    int findKthLargest(vector<int> &nums, int k) {
        --k;
        int start = 0, end = nums.size() - 1;
        while (true) {
            int i = select(nums, start, end);

            if (i == k) {
                return nums[i];
            }

            if (i < k) {
                start = i + 1;
            } else {
                end = i - 1;
            }
        }
    }
};

#endif //LEETCODE_0215_H
