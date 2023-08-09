#ifndef LEETCODE_1281_H
#define LEETCODE_1281_H

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, time = 1;

        while (n > 0) {
            int d = n % 10;
            sum += d;
            time *= d;
            n /= 10;
        }

        return time - sum;
    }
};

#endif //LEETCODE_1281_H
