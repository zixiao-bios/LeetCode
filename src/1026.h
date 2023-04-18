#ifndef LEETCODE_1026_H
#define LEETCODE_1026_H

#include "TreeNode.h"

class Solution {
public:
    int maxAncestorDiff(TreeNode *root) {
        int a, b;
        return max_diff(root, a, b);
    }

    int max_diff(const TreeNode *root, int &max_val, int &min_val) {
        if (root == nullptr) {
            max_val = -1;
            min_val = INT32_MAX;
            return 0;
        }

        int l_max_val, l_min_val, r_max_val, r_min_val;
        int l_diff = max_diff(root->left, l_max_val, l_min_val);
        int r_diff = max_diff(root->right, r_max_val, r_min_val);

        max_val = std::max(l_max_val, r_max_val);
        min_val = std::min(l_min_val, r_min_val);

        int max_diff = std::max(l_diff, r_diff);
        if (max_val != -1) {
            max_diff = std::max(max_diff, std::abs(root->val - max_val));
        }
        if (min_val != INT32_MAX) {
            max_diff = std::max(max_diff, std::abs(root->val - min_val));
        }

        max_val = std::max(max_val, root->val);
        min_val = std::min(min_val, root->val);
        return max_diff;
    }
};

#endif //LEETCODE_1026_H
