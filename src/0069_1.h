#ifndef LEETCODE_0069_1_H
#define LEETCODE_0069_1_H

/// 二分法

class Solution {
public:
    int mySqrt(int x) {
        int ans, mid;
        int start = 0;
        int end = x;

        while (start <= end) {
            mid = start + ((end - start) >> 1);
            if ((long long) mid * mid <= x) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0069_1_H
