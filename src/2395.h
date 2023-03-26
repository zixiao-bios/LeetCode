#ifndef LEETCODE_2395_H
#define LEETCODE_2395_H

#include <vector>
#include <unordered_set>

using std::vector;

class Solution {
public:
    bool findSubarrays(vector<int> &nums) {
        std::unordered_set<int> set{};
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (set.find(nums[i] + nums[i + 1]) != set.end()) {
                return true;
            }
            set.insert(nums[i] + nums[i + 1]);
        }
        return false;
    }
};

#endif //LEETCODE_2395_H
