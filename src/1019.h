#ifndef LEETCODE_1019_H
#define LEETCODE_1019_H

/**
 * 从左向右遍历链表，同时维护一个单调递减栈
 *
 * 对于目前遍历到的元素 x，要从栈中找到 x 是哪些元素的下一个更大元素：
 * 若 x > stack.top()，则 x 为栈顶元素的下一个更大元素，记录，并出栈
 * 重复执行，直到 x !> stack.top() 或栈空
 * x 入栈
 */

#include "ListNode.h"
#include <vector>
#include <stack>

using std::vector;

class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> ans;
        std::stack<std::pair<int, int>> stack;
        for (auto p = head; p != nullptr; p = p->next) {
            ans.push_back(0);
            while (!stack.empty() and p->val > stack.top().second) {
                ans[stack.top().first] = p->val;
                stack.pop();
            }
            stack.emplace(ans.size() - 1, p->val);
        }
        return ans;
    }
};

#endif //LEETCODE_1019_H
