#ifndef LEETCODE_2331_H
#define LEETCODE_2331_H

#include "TreeNode.h"

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->right == nullptr) {
            return root->val;
        } else {
            if (root->val == 2) {
                return evaluateTree(root->left) or evaluateTree(root->right);
            } else {
                return evaluateTree(root->left) and evaluateTree(root->right);
            }
        }
    }
};

#endif //LEETCODE_2331_H
