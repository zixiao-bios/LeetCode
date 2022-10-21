#ifndef LEETCODE_0104_H
#define LEETCODE_0104_H

#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

#endif //LEETCODE_0104_H
