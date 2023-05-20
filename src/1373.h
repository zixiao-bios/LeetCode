#ifndef LEETCODE_1373_H
#define LEETCODE_1373_H

#include <TreeNode.h>
#include <tuple>

class Solution {
public:
    int max_sum = 0;

    int maxSumBST(TreeNode *root) {
        is_search_tree(root);
        return max_sum;
    }

    ///
    /// \param root 树的根节点
    /// \param max_val_out 整棵树中最大的节点值
    /// \param min_val_out 整棵树中最小的节点值
    /// \param sum_out 整棵树的所有节点和
    /// \return 该树是否为搜索树
    std::tuple<bool, int, int, int> is_search_tree(TreeNode *root) {
        int max_val = root->val;
        int min_val = root->val;

        bool ok = true;
        int left_sum, right_sum;
        if (root->left == nullptr) {
            left_sum = 0;
        } else {
            auto [left_ok, left_max, left_min, t] = is_search_tree(root->left);
            left_sum = t;
            max_val = std::max(max_val, left_max);
            min_val = std::min(min_val, left_min);
            if (not(left_max < root->val and left_ok)) {
                ok = false;
            }
        }
        if (root->right == nullptr) {
            right_sum = 0;
        } else {
            auto [right_ok, right_max, right_min, t] = is_search_tree(root->right);
            right_sum = t;
            max_val = std::max(max_val, right_max);
            min_val = std::min(min_val, right_min);
            if (not(right_min > root->val and right_ok)) {
                ok = false;
            }
        }

        int sum = right_sum + left_sum + root->val;
        if (ok) {
            max_sum = std::max(max_sum, sum);
        }

        return {ok, max_val, min_val, sum};
    }
};

#endif //LEETCODE_1373_H
