#ifndef LEETCODE_0167_H
#define LEETCODE_0167_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            }

            if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }

        return {};
    }
};

#endif //LEETCODE_0167_H
