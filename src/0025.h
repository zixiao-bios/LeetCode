#ifndef LEETCODE_0025_H
#define LEETCODE_0025_H

#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 1) {
            return head;
        }

        ListNode front(0, head);
        int len = 0;

        ListNode *p = front.next;
        while (p != nullptr) {
            ++len;
            p = p->next;
        }

        p = &front;
        for (int i = 0; i < len / k; ++i) {
            p = reverse_k(p, k);
        }

        return front.next;
    }

    ///
    /// \param front 待翻转序列的前置节点
    /// \param k 待翻转序列的长度
    /// \return 翻转后序列的尾节点
    ListNode* reverse_k(ListNode *front, int k) {
        ListNode *rear = front->next;
        ListNode *target;

        for (int i = 0; i < k - 1; ++i) {
            target = rear->next;
            rear->next = target->next;
            target->next = front->next;
            front->next = target;
        }

        return rear;
    }
};

#endif //LEETCODE_0025_H
