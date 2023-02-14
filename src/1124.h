#ifndef LEETCODE_1124_H
#define LEETCODE_1124_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestWPI(vector<int> &hours) {
        int n = hours.size();

        /**
         * prefix_sum[i] = sum(hours[j]), j=[0,i)
         * prefix_sum[i] > 0 表示 [0, i) 天是表现良好的
         * prefix_sum[r] - prefix_sum[l] > 0 表示 [l, r) 天是表现良好的
         * 因此要寻找满足 prefix_sum[r] > prefix_sum[l] 的尽可能长的区间，区间长度为 r - l
         */
        vector<int> prefix_sum(n + 1, 0);
        stack<int> mono_stack;
        mono_stack.push(0);
        for (int i = 1; i < n + 1; ++i) {
            if (hours[i - 1] > 8) {
                prefix_sum[i] = prefix_sum[i - 1] + 1;
            } else {
                prefix_sum[i] = prefix_sum[i - 1] - 1;
            }

            if (prefix_sum[i] < prefix_sum[mono_stack.top()]) {
                mono_stack.push(i);
            }
        }

        int ans = 0;
        for (int i = n; i > 0; --i) {
            while (!mono_stack.empty() and prefix_sum[i] > prefix_sum[mono_stack.top()]) {
                ans = max(ans, i - mono_stack.top());
                mono_stack.pop();
            }
        }

        return ans;
    }
};

#endif //LEETCODE_1124_H
