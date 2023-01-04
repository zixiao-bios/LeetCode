#ifndef LEETCODE_0083_H
#define LEETCODE_0083_H

#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *p = head, *last_p = head;
        int last_value = head->val + 1;

        while (p != nullptr) {
            if (p->val == last_value) {
                // 删除p指向的结点
                last_p->next = p->next;
                ListNode *t = p;
                p = p->next;
                delete t;
            } else {
                last_value = p->val;
                last_p = p;
                p = p->next;
            }
        }

        return head;
    }
};

#endif //LEETCODE_0083_H
