#ifndef LEETCODE_0069_2_H
#define LEETCODE_0069_2_H

/// 牛顿迭代法

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double x0 = x;
        double xi;
        while (true) {
            xi = 0.5 * (x0 + (double) x / x0);
            if (x0 - xi < 1e-7) {
                break;
            }
            x0 = xi;
        }

        return (int) xi;
    }
};

#endif //LEETCODE_0069_2_H
