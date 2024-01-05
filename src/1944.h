#ifndef LEETCODE_1944_H
#define LEETCODE_1944_H

/**
 * 从右往左遍历，每个人会挡住右侧比自己矮的
 * 维持一个单调递增的栈，遍历到 k 时
 *      如果栈顶 < k，则：
 *          栈顶不可能被 k 之后的看到，所以出栈
 *          k也可以看到栈顶，因为k和栈顶之间不存在比k高的，不然k早就出栈了，所以k看到的个数+1
 *          k还有可能看到栈里其他人，继续循环
 *      如果栈顶 > k，则：
 *          k挡不住栈顶，更挡不住栈里其他人，所以k直接入栈
 *          k也可以看到栈顶，所以k看到的个数+1
 *          k无法看到栈里面其他人，所以退出循环，继续遍历
 *      如果栈空：则：
 *          k挡不住任何人，入栈
 *          k看不到人
 *          退出循环
 */

#include <vector>
#include <stack>

using std::vector;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int> &heights) {
        auto n = heights.size();
        std::stack<int> stack;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            while (true) {
                if (stack.empty()) {
                    stack.push(heights[i]);
                    break;
                } else if (heights[i] > stack.top()) {
                    stack.pop();
                    ++ans[i];
                } else {
                    stack.push(heights[i]);
                    ++ans[i];
                    break;
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODE_1944_H
