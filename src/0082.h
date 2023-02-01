#ifndef LEETCODE_0082_H
#define LEETCODE_0082_H

#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode front(head->val - 1, head);
        ListNode *p = &front;
        int delete_val = p->val;

        while (p->next != nullptr) {
            if (p->next->val == delete_val) {
                // delete p->next
                ListNode *target = p->next;
                p->next = target->next;
                delete target;
            } else {
                if (p->next->next != nullptr and p->next->val == p->next->next->val) {
                    delete_val = p->next->val;
                } else {
                    p = p->next;
                }
            }
        }

        return front.next;
    }
};

#endif //LEETCODE_0082_H
