#ifndef LEETCODE_1574_H
#define LEETCODE_1574_H

#include <vector>

using std::vector;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int> &arr) {
        int n = arr.size();

        // arr 的 [0, right] 和 [left, n - 1] 拼成了非递减序列
        int right, left = n - 1;

        // left 最小为最长非递减后缀的首元素索引
        while (left > 0 and arr[left - 1] <= arr[left]) {
            --left;
        }
        if (left == 0) {
            return 0;
        }

        int ans = left;
        // 遍历 right 的所有可能，且此时 arr 一定不是非递减的
        for (right = 0; right == 0 or arr[right - 1] <= arr[right]; ++right) {
            while (left < n and arr[left] < arr[right]) {
                ++left;
            }
            ans = std::min(ans, left - right - 1);
        }
        return ans;
    }
};

#endif //LEETCODE_1574_H
