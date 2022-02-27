#ifndef LEETCODE_0002_H
#define LEETCODE_0002_H


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *lastNode = nullptr;
    ListNode *firstNode = nullptr;

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        bool carry = false;

        while (true) {
            if (l1 == nullptr) {
                while (l2 != nullptr) {
                    carry = insertNode(l2->val + carry);
                    l2 = l2->next;
                }
                if (carry) {
                    insertNode(1);
                }
                break;
            }

            if (l2 == nullptr) {
                while (l1 != nullptr) {
                    carry = insertNode(l1->val + carry);
                    l1 = l1->next;
                }
                if (carry) {
                    insertNode(1);
                }
                break;
            }

            int n = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;

            carry = insertNode(n);
        }

        return this->firstNode;
    }

    bool insertNode(int val) {
        bool carry;
        if (val >= 10) {
            carry = true;
            val %= 10;
        } else {
            carry = false;
        }

        auto *newNode = new ListNode(val);

        if (this->lastNode) {
            lastNode->next = newNode;
        } else {
            this->firstNode = newNode;
        }

        this->lastNode = newNode;
        return carry;
    }
};

#endif //LEETCODE_0002_H
