#ifndef LEETCODE_1110_H
#define LEETCODE_1110_H

#include <vector>
#include <unordered_set>
#include "TreeNode.h"

using std::vector;

class Solution {
public:
    std::unordered_set<TreeNode *> root_set;
    std::unordered_set<int> delete_set;

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        root_set.insert(root);

        for (const auto &each: to_delete) {
            delete_set.insert(each);
        }

        auto *head = new TreeNode(0, root, nullptr);
        del_tree(root, head);

        std::vector<TreeNode *> ans;
        ans.reserve(root_set.size());
        for (const auto &each: root_set) {
            ans.push_back(each);
        }
        return ans;
    }

    void del_tree(TreeNode *root, TreeNode *par) {
        if (root == nullptr) {
            return;
        }

        if (delete_set.find(root->val) != delete_set.end()) {
            if (par->left == root) {
                par->left = nullptr;
            } else {
                par->right = nullptr;
            }

            if (root_set.find(root) != root_set.end()) {
                root_set.erase(root);
            }

            if (root->left != nullptr) {
                root_set.insert(root->left);
            }
            if (root->right != nullptr) {
                root_set.insert(root->right);
            }
        }
        del_tree(root->left, root);
        del_tree(root->right, root);
    }
};

#endif //LEETCODE_1110_H
