#ifndef LEETCODE_1137_H
#define LEETCODE_1137_H

#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        vector<int> num = {0, 1, 1, 2};

        if (n < 4) {
            return num[n];
        }

        for (int i = 3; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                num[j] = num[j + 1];
            }
            num[3] = num[0] + num[1] + num[2];
        }

        return num[3];
    }
};

#endif //LEETCODE_1137_H
