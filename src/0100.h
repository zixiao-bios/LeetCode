#ifndef LEETCODE_0100_H
#define LEETCODE_0100_H

#include "TreeNode.h"

using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr and q == nullptr) {
            return true;
        } else if (p != nullptr and q != nullptr) {
            if (p->val == q->val) {
                return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

#endif //LEETCODE_0100_H
