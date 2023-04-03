#ifndef LEETCODE_1053_H
#define LEETCODE_1053_H

/**
 * 肯定要把一个靠前的较大元素(a)与靠后的较小元素(b)交换
 *
 * 首先要保证 a 的位置尽可能靠后，即 a 为倒序遍历时，第一个增大的元素。
 * 然后选择 b，首先要保证 b < a 且 b 尽可能大，其次是 b 尽可能靠前
 */

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int> &arr) {
        int n = arr.size();
        int idx_a = -1;

        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1]) {
                idx_a = i;
                break;
            }
        }
        if (idx_a == -1) {
            return arr;
        }

        int idx_b, b;
        for (int i = idx_a + 1; i < n and arr[i] < arr[idx_a];) {
            b = arr[i];
            idx_b = i;
            while (i < n and arr[i] == b) {
                ++i;
            }
        }

        std::swap(arr[idx_a], arr[idx_b]);
        return arr;
    }
};

#endif //LEETCODE_1053_H
