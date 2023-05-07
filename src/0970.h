#ifndef LEETCODE_0970_H
#define LEETCODE_0970_H

#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> x_pow, y_pow;

    std::vector<int> powerfulIntegers(int x, int y, int bound) {
        compute_pow(x, bound, x_pow);
        compute_pow(y, bound, y_pow);

        std::unordered_set<int> set;
        for (const auto &each_x: x_pow) {
            for (const auto &each_y: y_pow) {
                if (each_x + each_y <= bound) {
                    set.insert(each_x + each_y);
                } else {
                    break;
                }
            }
        }
        return {set.begin(), set.end()};
    }

    static void compute_pow(int n, int bound, std::vector<int> &output) {
        if (n == 1) {
            if (1 <= bound) {
                output.push_back(1);
            }
            return;
        }

        int pow = 1;
        while (pow <= bound) {
            output.push_back(pow);
            pow *= n;
        }
    }
};

#endif //LEETCODE_0970_H
