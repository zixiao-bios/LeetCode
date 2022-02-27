#ifndef LEETCODE_0633_H
#define LEETCODE_0633_H

#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int max = (int) sqrt(c);

        long long l = 0, r = max, value;
        while (l <= r) {
            value = l * l + r * r;
            if (value == c) {
                return true;
            } else if (value < c) {
                ++l;
            } else {
                --r;
            }
        }

        return false;
    }
};

#endif //LEETCODE_0633_H
