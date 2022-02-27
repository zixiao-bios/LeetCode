#ifndef LEETCODE_0020_H
#define LEETCODE_0020_H

#include <stack>
#include <set>

using namespace std;

set<int, char> a;

class Solution {
public:
    bool isValid(string s) {
        char open[3] = {'(', '[', '{'};
        char close[3] = {')', ']', '}'};
        stack<char> stack;

        for (char ch : s) {
            if (indexOf(close, ch) != -1) {
                // ch is close
                if (stack.empty() or indexOf(open, stack.top()) != indexOf(close, ch)) {
                    return false;
                } else {
                    stack.pop();
                }
            } else {
                // ch is open
                stack.push(ch);
            }
        }

        return stack.empty();
    }

    int indexOf(const char arry[], char ch) {
        for (int i = 0; i < 3; ++i) {
            if (arry[i] == ch) {
                return i;
            }
        }
        return -1;
    }
};

#endif //LEETCODE_0020_H
