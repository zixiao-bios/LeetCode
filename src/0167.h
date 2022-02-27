#ifndef LEETCODE_0167_H
#define LEETCODE_0167_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() -1;
        int sum;

        while (i < j) {
            sum = numbers[i] + numbers[j];

            if (sum == target) {
                return {i + 1, j + 1};
            }

            if (sum < target) {
                ++i;
            } else {
                --j;
            }
        }

        return {};
    }
};

#endif //LEETCODE_0167_H
