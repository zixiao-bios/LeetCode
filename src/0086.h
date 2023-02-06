#ifndef LEETCODE_0086_H
#define LEETCODE_0086_H

#include "ListNode.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode front(0, head);
        ListNode *p = &front;

        while (p->next != nullptr and p->next->val < x) {
            p = p->next;
        }

        if (p->next == nullptr) {
            return head;
        }

        ListNode *insert_pos = p;
        while (p->next != nullptr) {
            if (p->next->val < x) {
                // move p->next back to insert_pos
                ListNode *target = p->next;
                p->next = target->next;
                target->next = insert_pos->next;
                insert_pos->next = target;
                insert_pos = target;
            } else {
                p = p->next;
            }
        }

        return front.next;
    }
};

#endif //LEETCODE_0086_H
