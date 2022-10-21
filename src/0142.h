#ifndef LEETCODE_0142_H
#define LEETCODE_0142_H

#include "list_node.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while (true) {
            if (fast == nullptr or fast->next == nullptr) {
                return nullptr;
            }

            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                break;
            }
        }

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};

#endif //LEETCODE_0142_H
