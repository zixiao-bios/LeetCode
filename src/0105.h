#ifndef LEETCODE_0105_H
#define LEETCODE_0105_H

#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, int> index;
    vector<int> pre, in;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        this->pre = preorder;
        this->in = inorder;

        int n = preorder.size();

        for (int i = 0; i < n; ++i) {
            this->index[inorder[i]] = i;
        }

        return build(0, n - 1, 0, n - 1);
    }

    TreeNode *build(int pre_start, int pre_end, int in_start, int in_end) {
        if (pre_end < pre_start) {
            return nullptr;
        }

        auto *root = new TreeNode(this->pre[pre_start]);
        int in_idx = this->index[root->val];

        int lc_len = in_idx - in_start;
        int rc_len = in_end - in_idx;

        root->left = build(pre_start + 1, pre_start + lc_len, in_start, in_start + lc_len - 1);
        root->right = build(pre_end - rc_len + 1, pre_end, in_end - rc_len + 1, in_end);

        return root;
    }
};

#endif //LEETCODE_0105_H
