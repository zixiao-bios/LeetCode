#ifndef LEETCODE_0007_H
#define LEETCODE_0007_H

class Solution {
public:
    int reverse(int x) {
        int res = 0, digital;

        while (x != 0) {
            if (res < INT_MIN / 10 or res > INT_MAX / 10) {
                return 0;
            }

            digital = x % 10;
            x /= 10;
            res = res * 10 + digital;
        }

        return res;
    }
};

#endif //LEETCODE_0007_H
