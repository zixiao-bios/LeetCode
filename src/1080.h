#ifndef LEETCODE_1080_H
#define LEETCODE_1080_H

#include "TreeNode.h"

class Solution {
public:
    int min_val;

    TreeNode *sufficientSubset(TreeNode *root, int limit) {
        min_val = limit;
        auto *head = new TreeNode(0, root, nullptr);
        check(root, head, 0);
        return head->left;
    }

    ///
    /// \param node 需要检查的节点
    /// \param sum_to_root 从根结点到该结点的路径和（不包括该结点）
    /// \return 从该结点到其子树的所有叶子节点的路径中，最大的路径和（包括该结点）
    int check(TreeNode *node, TreeNode *par_node, int sum_to_root) {
        sum_to_root += node->val;
        int max_path;
        if (node->left == nullptr and node->right == nullptr) {
            max_path = 0;
        } else if (node->left != nullptr and node->right == nullptr) {
            max_path = check(node->left, node, sum_to_root);
        } else if (node->left == nullptr and node->right != nullptr) {
            max_path = check(node->right, node, sum_to_root);
        } else {
            max_path = std::max(check(node->left, node, sum_to_root),
                                check(node->right, node, sum_to_root));
        }

        int res = max_path + node->val;
        if (sum_to_root + max_path < min_val) {
            if (par_node->right == node) {
                par_node->right = nullptr;
            } else {
                par_node->left = nullptr;
            }
        }
        return res;
    }
};

#endif //LEETCODE_1080_H
