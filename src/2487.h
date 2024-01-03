#ifndef LEETCODE_2487_H
#define LEETCODE_2487_H

#include "ListNode.h"
#include <stack>

class Solution {
public:
    static void remove_node(ListNode *par) {
        auto t = par->next;
        par->next = t->next;
        delete t;
    }

    ListNode *removeNodes(ListNode *head) {
        std::stack<ListNode *> stack;

        ListNode front(0, head);

        auto p = head, par = &front;

        while (p != nullptr) {
            while (!stack.empty() and stack.top()->next->val < p->val) {
                Solution::remove_node(stack.top());
                par = stack.top();
                stack.pop();
            }
            stack.push(par);
            par = p;
            p = p->next;
        }

        return front.next;
    }
};

#endif //LEETCODE_2487_H
