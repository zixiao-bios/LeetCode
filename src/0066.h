#ifndef LEETCODE_0066_H
#define LEETCODE_0066_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] = (digits[i] + 1) % 10;
            if (digits[i] != 0) {
                return digits;
            }
        }

        vector<int> ans(digits.size() + 1, 0);
        ans[0] = 1;
        return ans;
    }
};

#endif //LEETCODE_0066_H
