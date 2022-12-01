#ifndef LEETCODE_0092_H
#define LEETCODE_0092_H

#include "ListNode.h"

using namespace std;

class Solution {
public:
    // 将source后方的节点插入到target节点的后面
    void insert(ListNode *target, ListNode *source) {
        if (target == nullptr or source == nullptr or source->next == nullptr) {
            return;
        }

        ListNode *x = source->next;
        source->next = x->next;
        x->next = target->next;
        target->next = x;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode front(0);
        front.next = head;

        ListNode *p = &front;
        for (int i = 0; i < left - 1; ++i) {
            p = p->next;
        }

        // 此时p指向left的上一个节点
        ListNode *target = p;

        p = p->next;
        for (int i = 0; i < right - left; ++i) {
            insert(target, p);
        }

        return front.next;
    }
};

#endif //LEETCODE_0092_H
