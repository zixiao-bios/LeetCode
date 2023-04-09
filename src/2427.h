#ifndef LEETCODE_2427_H
#define LEETCODE_2427_H

#include <numeric>
#include <cmath>

class Solution {
public:
    int commonFactors(int a, int b) {
        int c = std::gcd(a, b);
        int ans = 0;
        for (int i = 1; i * i <= c; ++i) {
            if (c % i == 0) {
                ans += 1 + (i * i != c);
            }
        }
        return ans;
    }
};

#endif //LEETCODE_2427_H
