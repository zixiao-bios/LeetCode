#ifndef LEETCODE_0023_H
#define LEETCODE_0023_H

#include "ListNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    ListNode *mergeList(ListNode *head1, ListNode *head2) {
        ListNode *p1 = head1;
        ListNode *p2 = head2;

        ListNode front;
        ListNode *rear = &front;
        bool finish = false;

        while (true) {
            if (finish) {
                return front.next;
            }

            if (p1 == nullptr) {
                // p1都排完了
                rear->next = p2;
                finish = true;
            } else if (p2 == nullptr) {
                // p2都排完了
                rear->next = p1;
                finish = true;
            } else {
                // 都没排完
                if (p1->val < p2->val) {
                    // 排p1
                    rear->next = p1;
                    p1 = p1->next;
                } else {
                    rear->next = p2;
                    p2 = p2->next;
                }
                rear = rear->next;
            }
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }

        ListNode *head1, *head2;

        while (lists.size() > 1) {
            auto it = lists.begin();

            while (it != lists.end()) {
                head1 = *it;
                if (it + 1 != lists.end()) {
                    // 不是最后一个
                    it = lists.erase(it);
                    head2 = *it;
                    *it = mergeList(head1, head2);
                }
                ++it;
            }
        }

        return lists[0];
    }
};

#endif //LEETCODE_0023_H
