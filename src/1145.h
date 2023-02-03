#ifndef LEETCODE_1145_H
#define LEETCODE_1145_H

#include "TreeNode.h"

class Solution {
public:
    int node_num(const TreeNode *root) {
        if (root == nullptr) {
            return 0;
        } else {
            return node_num(root->right) + node_num(root->left) + 1;
        }
    }

    const TreeNode *find_node(const TreeNode *root, int val) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == val) {
            return root;
        } else {
            const TreeNode *left_node = find_node(root->left, val);
            if (left_node) {
                return left_node;
            } else {
                return find_node(root->right, val);
            }
        }
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        const TreeNode *red = find_node(root, x);

        if (red != root) {
            // 选红色的父节点试试
            int red_num = node_num(red);
            if (n - red_num > red_num) {
                return true;
            }
        }

        // 选红色的子节点中，子孙数最多的节点
        int blue_num = std::max(node_num(red->left), node_num(red->right));
        return blue_num > n - blue_num;
    }
};

#endif //LEETCODE_1145_H
