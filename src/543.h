#ifndef LEETCODE_543_H
#define LEETCODE_543_H

#include <TreeNode.h>

class Solution {
public:
    int max_len = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        depth(root);
        return max_len;
    }

    int depth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        max_len = std::max(max_len, left + right);
        return std::max(left, right) + 1;
    }
};

#endif //LEETCODE_543_H
