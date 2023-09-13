#ifndef LEETCODE_1448_H
#define LEETCODE_1448_H

#include "TreeNode.h"

class Solution {
public:
    int ans = 0;

    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }

    void dfs(const TreeNode *node, int max_val) {
        if (node == nullptr) {
            return;
        }

        if (max_val <= node->val) {
            ++ans;
            max_val = node->val;
        }
        dfs(node->left, max_val);
        dfs(node->right, max_val);
    }
};

#endif //LEETCODE_1448_H
