#ifndef LEETCODE_LIST_NODE_H
#define LEETCODE_LIST_NODE_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

#endif //LEETCODE_LIST_NODE_H
