#ifndef LEETCODE_0042_2_H
#define LEETCODE_0042_2_H

#include <vector>
#include <stack>

using namespace std;

/// 单调栈方法：https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stack;
        int ans = 0;

        for (int i = 0; i < height.size(); ++i) {
            while (!stack.empty() and height[i] > height[stack.top()]) {
                int bottom_height = height[stack.top()];
                stack.pop();

                if (stack.empty()) {
                    break;
                }

                int left_index = stack.top();
                ans += (min(height[i], height[left_index]) - bottom_height) * (i - left_index - 1);
            }

            stack.push(i);
        }

        return ans;
    }
};

#endif //LEETCODE_0042_2_H
