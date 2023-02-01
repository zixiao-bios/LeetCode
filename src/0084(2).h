#ifndef LEETCODE_0084_2_H
#define LEETCODE_0084_2_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() and heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }

            if (mono_stack.empty()) {
                left[i] = -1;
            } else {
                left[i] = mono_stack.top();
            }

            mono_stack.push(i);
        }

        stack<int>().swap(mono_stack);
        for (int i = n - 1; i >= 0; --i) {
            while (!mono_stack.empty() and heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }

            if (mono_stack.empty()) {
                right[i] = n;
            } else {
                right[i] = mono_stack.top();
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

#endif //LEETCODE_0084_2_H
