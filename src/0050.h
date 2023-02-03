#ifndef LEETCODE_0050_H
#define LEETCODE_0050_H

class Solution {
public:
    double pow(double x, int n) {
        if (n == 1) {
            return x;
        } else if (n % 2 == 0) {
            double y = pow(x, n / 2);
            return y * y;
        } else {
            double y = pow(x, (n - 1) / 2);
            return y * y * x;
        }
    }

    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        } else if (n == INT32_MIN) {
            return 1 / (x * pow(x, -(n + 1)));
        } else if (n < 0) {
            return 1 / pow(x, -n);
        } else {
            return pow(x, n);
        }
    }
};

#endif //LEETCODE_0050_H
