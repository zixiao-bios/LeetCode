#ifndef LEETCODE_0024_H
#define LEETCODE_0024_H

#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr or head->next == nullptr) {
            return head;
        }

        auto *start = new ListNode();
        start->next = head;

        ListNode *prev = start, *left = head, *right = head->next;

        while (true) {
            prev->next = right;
            left->next = right->next;
            right->next = left;

            if (left->next == nullptr or left->next->next == nullptr) {
                break;
            } else {
                prev = left;
                left = prev->next;
                right = left->next;
            }
        }

        return start->next;
    }
};

#endif //LEETCODE_0024_H
