#ifndef LEETCODE_0061_H
#define LEETCODE_0061_H

#include "ListNode.h"

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode front(0, head);
        ListNode *rear_old = &front;

        int len = 0;
        while (rear_old->next != nullptr) {
            rear_old = rear_old->next;
            ++len;
        }

        k = k % len;
        if (k == 0) {
            return head;
        }

        ListNode *rear_new = &front;
        for (int i = 0; i < len - k; ++i) {
            rear_new = rear_new->next;
        }

        front.next = rear_new->next;
        rear_old->next = head;
        rear_new->next = nullptr;

        return front.next;
    }
};

#endif //LEETCODE_0061_H
