#ifndef LEETCODE_1250_H
#define LEETCODE_1250_H

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool isGoodArray(vector<int> &nums) {
        int a = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            a = gcd(a, nums[i]);
        }
        return a == 1;
    }
};

#endif //LEETCODE_1250_H
