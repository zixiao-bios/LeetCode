#ifndef LEETCODE_0142_H
#define LEETCODE_0142_H

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };


    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        do {
            if (fast == nullptr or fast->next == nullptr) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        } while (fast != slow);

        fast = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};

#endif //LEETCODE_0142_H
