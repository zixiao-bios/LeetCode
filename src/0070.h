#ifndef LEETCODE_0070_H
#define LEETCODE_0070_H

class Solution {
public:
    int climbStairs(int n) {
        int num[3] = {1, 2, -1};

        if (n < 3) {
            return num[n - 1];
        }

        for (int i = 2; i < n; ++i) {
            num[2] = num[0] + num[1];
            num[0] = num[1];
            num[1] = num[2];
        }

        return num[2];
    }
};

#endif //LEETCODE_0070_H
