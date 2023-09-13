#ifndef LEETCODE_0617_2_H
#define LEETCODE_0617_2_H

#include "TreeNode.h"

class Solution {
public:
    // 合并 root1 和 root2 为根节点的树，并返回合并后的树的根节点
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }

        return new TreeNode(root1->val + root2->val, mergeTrees(root1->left, root2->left),
                            mergeTrees(root1->right, root2->right));
    }
};

#endif //LEETCODE_0617_2_H
