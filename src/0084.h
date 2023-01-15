#ifndef LEETCODE_0084_H
#define LEETCODE_0084_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();

        // 分别表示第i个柱子右侧和左侧的最近的高度小于自身的柱子索引
        vector<int> right(n), left(n);

        stack<int> mono_stack;
        mono_stack.push(-1);
        for (int i = 0; i < n; ++i) {
            while (true) {
                if (mono_stack.top() == -1 or heights[mono_stack.top()] < heights[i]) {
                    // i柱子左侧没有更矮的柱子了，或者找到了更矮的柱子
                    left[i] = mono_stack.top();
                    break;
                } else {
                    // 栈顶的柱子更高，舍弃，并继续寻找
                    mono_stack.pop();
                }
            }
            mono_stack.push(i);
        }

        stack<int>().swap(mono_stack);
        mono_stack.push(n);
        for (int i = n - 1; i >= 0; --i) {
            while (true) {
                if (mono_stack.top() == n or heights[mono_stack.top()] < heights[i]) {
                    right[i] = mono_stack.top();
                    break;
                } else {
                    mono_stack.pop();
                }
            }
            mono_stack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }

        return ans;
    }
};

#endif //LEETCODE_0084_H
