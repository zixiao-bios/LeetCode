#ifndef LEETCODE_0633_H
#define LEETCODE_0633_H

#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long right = int(sqrt(c)), left = 0;

        while (left <= right) {
            long long res = left * left + right * right;
            if (res == c) {
                return true;
            } else if (res < c) {
                ++left;
            } else {
                --right;
            }
        }

        return false;
    }
};

#endif //LEETCODE_0633_H
