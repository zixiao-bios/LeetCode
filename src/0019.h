#ifndef LEETCODE_0019_H
#define LEETCODE_0019_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto *dummy = new ListNode(-1, head);
        ListNode *l = dummy, *r = dummy;

        for (int i = 0; i < n; ++i) {
            r = r->next;
        }

        while (r->next != nullptr) {
            r = r->next;
            l = l->next;
        }

        l->next = l->next->next;

        return dummy->next;
    }
};

#endif //LEETCODE_0019_H
