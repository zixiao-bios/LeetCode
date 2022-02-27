#ifndef LEETCODE_1_H
#define LEETCODE_1_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        int n;

        for (int i = 0; i < nums.size(); i++) {
            n = target - nums[i];

            if (map.find(n) != map.end()) {
                return {i, map.find(n)->second};
            }

            map[nums[i]] = i;
        }

        return {};
    }
};

#endif //LEETCODE_1_H
