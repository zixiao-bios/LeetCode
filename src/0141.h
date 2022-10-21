#ifndef LEETCODE_0141_H
#define LEETCODE_0141_H

#include "ListNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while (fast != nullptr and fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};

#endif //LEETCODE_0141_H
