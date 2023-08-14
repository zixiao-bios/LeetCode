#ifndef LEETCODE_0617_H
#define LEETCODE_0617_H

#include "TreeNode.h"

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr and root2 == nullptr) {
            return nullptr;
        }

        auto *const new_root = new TreeNode();
        merge_node(root1, root2, new_root);
        return new_root;
    }

    // 调用时保证 node1 和 node2 不同时为 nullptr
    void merge_node(const TreeNode *const node1, const TreeNode *const node2, TreeNode *const new_node) {
        static auto create_node =
                [this](TreeNode *&par_child, const TreeNode *const child1, const TreeNode *const child2) {
                    auto *new_child = new TreeNode();
                    par_child = new_child;
                    merge_node(child1, child2, new_child);
                };

        if (node1 == nullptr or node2 == nullptr) {
            auto node_x = node1 == nullptr ? node2 : node1;
            new_node->val = node_x->val;
            if (node_x->left != nullptr) {
                create_node(new_node->left, node_x->left, nullptr);
            }
            if (node_x->right != nullptr) {
                create_node(new_node->right, node_x->right, nullptr);
            }
        } else {
            new_node->val = node1->val + node2->val;
            if (node1->left != nullptr or node2->left != nullptr) {
                create_node(new_node->left, node1->left, node2->left);
            }
            if (node1->right != nullptr or node2->right != nullptr) {
                create_node(new_node->right, node1->right, node2->right);
            }
        }
    }
};

#endif //LEETCODE_0617_H
