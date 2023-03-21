#ifndef LEETCODE_2469_H
#define LEETCODE_2469_H

#include <vector>

using std::vector;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.8 + 32};
    }
};

#endif //LEETCODE_2469_H
