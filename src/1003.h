#ifndef LEETCODE_1003_H
#define LEETCODE_1003_H

/**
 * 有效字符串中，每个连续的 “abc” 左侧一定是 “abc“ 的前缀，右侧一定是后缀
 * 从前向后遍历字符串，如果遇到 “abc” 的前缀，则将其入栈；如果遇到 “abc” 则跳过；如果遇到后缀，则与栈顶元素组合。
 */

#include <stack>
#include <unordered_set>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<std::string> stack;

        for (const char &ch: s) {
            if (!stack.empty() and ch - *(stack.top().end() - 1) == 1) {
                stack.top() += ch;
                if (stack.top() == "abc") {
                    stack.pop();
                }
            } else {
                stack.emplace(1, ch);
            }
        }

        return stack.empty();
    }
};

#endif //LEETCODE_1003_H
