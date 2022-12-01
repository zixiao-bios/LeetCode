#ifndef LEETCODE_148_H
#define LEETCODE_148_H

#include "ListNode.h"

class Solution {
public:
    ///
    /// \param a a的开始节点，无头节点，下同
    /// \param b
    /// \return 合并后的链表的开始节点，无头结点
    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode *pa = a, *pb = b, *p, *head;
        if (pa->val < pb->val) {
            p = pa;
            pa = pa->next;
        } else {
            p = pb;
            pb = pb->next;
        }
        head = p;

        while (true) {
            if (pa == nullptr) {
                p->next = pb;
                break;
            }

            if (pb == nullptr) {
                p->next = pa;
                break;
            }

            if (pa->val < pb->val) {
                p->next = pa;
                pa = pa->next;
            } else {
                p->next = pb;
                pb = pb->next;
            }
            p = p->next;
        }

        return head;
    }

    ///
    /// \param p 开始节点，无头节点
    /// \param len 期望长度
    /// \param head 子链表的开始节点，无头节点
    /// \param end
    /// \return 状态：0=找到符合长度的链表，1=找到链表但长度不足，2=不存在链表(p==nullptr)。最后一种情况时，head和end为nullptr
    int findSubList(ListNode *p, int len, ListNode **head, ListNode **end) {
        if (p == nullptr) {
            *head = nullptr;
            *end = nullptr;
            return 2;
        }

        *head = p;
        for (int i = 0;; ++i) {
            if (i == len - 1) {
                *end = p;
                return 0;
            }

            if (p->next == nullptr) {
                *end = p;
                return 1;
            }

            p = p->next;
        }
    }

    ListNode *sortList(ListNode *head) {
        int length = 0;
        ListNode *p = head;
        while (p != nullptr) {
            ++length;
            p = p->next;
        }

        if (length < 2) {
            return head;
        }

        auto *front = new ListNode(0);
        front->next = head;

        ListNode *a_head, *a_end, *b_head, *b_end, *merged_end, *last_merged_end;
        bool finish;
        for (int sub_len = 1; sub_len < length; sub_len *= 2) {
            finish = false;
            p = front->next;
            last_merged_end = front;

            while (true) {
                // 找a
                switch (findSubList(p, sub_len, &a_head, &a_end)) {
                    case 1:
                    case 2:
                        // a长度不足或不存在，本轮结束
                        finish = true;
                }
                if (finish) {
                    break;
                }

                // 找b
                p = a_end->next;
                switch (findSubList(p, sub_len, &b_head, &b_end)) {
                    case 2:
                        // b不存在，本轮结束
                        finish = true;
                }
                if (finish) {
                    break;
                }

                // a和b都存在，开始合并
                p = b_end->next;
                a_end->next = nullptr;
                b_end->next = nullptr;

                last_merged_end->next = merge(a_head, b_head);
                merged_end = a_end->val >= b_end->val ? a_end : b_end;
                merged_end->next = p;
                last_merged_end = merged_end;
            }
        }

        return front->next;
    }
};

#endif //LEETCODE_148_H
