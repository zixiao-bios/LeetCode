#ifndef LEETCODE_1238_H
#define LEETCODE_1238_H

#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    static vector<int> gray_code(int n) {
        vector<int> res(1 << n);
        res[0] = 0, res[1] = 1;

        int head = 0b10;
        int step = 2;
        for (int i = 2; i < res.size();) {
            for (int j = step - 1; j >= 0; --j) {
                res[i] = head + res[j];
                ++i;
            }
            head <<= 1;
            step *= 2;
        }
        return res;
    }

    static vector<int> circularPermutation(int n, int start) {
        auto gray_code = Solution::gray_code(n);

        for (auto &each: gray_code) {
            each ^= start;
        }

        return gray_code;
    }
};

#endif //LEETCODE_1238_H
