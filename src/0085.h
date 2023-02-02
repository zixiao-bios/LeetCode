#ifndef LEETCODE_0085_H
#define LEETCODE_0085_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int find_max_area(const vector<int> &heights) {
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;

        vector<int> heights(n), last_heights(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] = last_heights[j] + 1;
                } else {
                    heights[j] = 0;
                }
            }

            ans = max(ans, find_max_area(heights));
            last_heights.swap(heights);
        }

        return ans;
    }
};

#endif //LEETCODE_0085_H
