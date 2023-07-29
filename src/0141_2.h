#ifndef LEETCODE_0141_2_H
#define LEETCODE_0141_2_H

#include "ListNode.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        auto fast = head, slow = head;
        while (true) {
            if (fast->next == nullptr or fast->next->next == nullptr) {
                return false;
            }

            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};

#endif //LEETCODE_0141_2_H
