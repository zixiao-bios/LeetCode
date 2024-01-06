#ifndef LEETCODE_2807_H
#define LEETCODE_2807_H

#include "ListNode.h"

class Solution {
public:
    static int gcd(int a, int b) {
        if (a % b == 0) {
            return b;
        } else {
            return gcd(b, a % b);
        }
    }

    static void insert(ListNode *par, int val) {
        auto node = new ListNode(val, par->next);
        par->next = node;
    }

    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        auto p = head;

        while (p != nullptr and p->next != nullptr) {
            Solution::insert(p, Solution::gcd(p->val, p->next->val));
            p = p->next->next;
        }
        return head;
    }
};

#endif //LEETCODE_2807_H
