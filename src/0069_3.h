#ifndef LEETCODE_0069_3_H
#define LEETCODE_0069_3_H

/// 梯度下降法, https://blog.csdn.net/weixin_39244297/article/details/108772358

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    double mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double step = 0.1 / x;
        double value = 1;

        while (std::abs(value * value - x) > 1e-5) {
            value = value - 4 * step * value * (value * value - x);
        }

        int ans = (int) round(value);
        return (long long) ans * ans <= x ? ans : ans - 1;
    }
};

#endif //LEETCODE_0069_3_H
