#ifndef LEETCODE_0509_H
#define LEETCODE_0509_H

class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }

        int a = 0;
        int b = 1;
        int c = 1;

        for (int i = 2; i < n; ++i) {
            a = b;
            b = c;
            c = a + b;
        }

        return c;
    }
};

#endif //LEETCODE_0509_H
