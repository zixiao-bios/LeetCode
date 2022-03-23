#ifndef LEETCODE_0102_H
#define LEETCODE_0102_H

#include "TreeNode.h"
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> ans;

        auto *endFlag = new TreeNode();
        queue<TreeNode *> queue;
        queue.push(root);
        queue.push(endFlag);

        vector<int> nodeList = {};
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();

            if (node == endFlag) {
                // 当前层已遍历完
                queue.push(endFlag);

                if (nodeList.empty()) {
                    break;
                } else {
                    ans.push_back(nodeList);
                    nodeList = {};
                }
            } else if (node) {
                // 新节点
                queue.push(node->left);
                queue.push(node->right);

                nodeList.push_back(node->val);
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0102_H
