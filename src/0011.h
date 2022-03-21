#ifndef LEETCODE_0011_H
#define LEETCODE_0011_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            max = std::max(max, min(height[left], height[right]) * (right - left));
            height[left] < height[right] ? ++left : --right;
        }

        return max;
    }
};

#endif //LEETCODE_0011_H
