#ifndef LEETCODE_2367_H
#define LEETCODE_2367_H

#include <vector>
#include <unordered_set>

using std::vector;

class Solution {
public:
    int arithmeticTriplets(vector<int> &nums, int diff) {
        std::unordered_set<int> values;
        for (const auto &num: nums) {
            values.insert(num);
        }

        int ans = 0;
        for (int num : nums) {
            if (values.find(num + diff) != values.end() and
                values.find(num + 2 * diff) != values.end()) {
                ++ans;
            }
        }
        return ans;
    }
};

#endif //LEETCODE_2367_H
