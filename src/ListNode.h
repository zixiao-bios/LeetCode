#ifndef LEETCODE_LISTNODE_H
#define LEETCODE_LISTNODE_H

struct ListNode {
    int val{};
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : next(nullptr) {}
};

#endif //LEETCODE_LISTNODE_H
