#ifndef LEETCODE_1617_H
#define LEETCODE_1617_H

#include <vector>
#include <unordered_set>

using std::vector;

class Solution {
public:
    vector<vector<int>> tree;
    vector<int> ans;

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges) {
        tree = vector(n, vector<int>{});
        ans = vector(n - 1, 0);
        for (const auto &edge: edges) {
            tree[edge[0] - 1].push_back(edge[1] - 1);
            tree[edge[1] - 1].push_back(edge[0] - 1);
        }

        std::unordered_set<int> set{};
        sub_set(n, 0, set);
        return ans;
    }

    // 从n节点开始dfs，并且只遍历set中的节点
    // 将遍历过的点记录在visited中，将子树直径存在diameter中
    // 返回以n为根节点的树的高度
    int depth(const std::unordered_set<int> &set, int n, std::unordered_set<int> &visited, int &diameter) {
        if (set.find(n) == set.end() or visited.find(n) != visited.end()) {
            return 0;
        }
        visited.insert(n);

        int max1 = 0, max2 = 0;
        for (auto child: tree[n]) {
            int d = depth(set, child, visited, diameter);
            if (d >= max1) {
                max2 = max1;
                max1 = d;
            } else if (d > max2) {
                max2 = d;
            }
        }

        diameter = std::max(diameter, max1 + max2);
        return max1 + 1;
    }

    void sub_set(int n, int level, std::unordered_set<int> &set) {
        if (level == n) {
            // find a sub set
            if (set.empty()) {
                return;
            }
            std::unordered_set<int> visited{};
            int diameter = 0;
            depth(set, *set.begin(), visited, diameter);
            if (visited == set and diameter > 0) {
                ++ans[diameter - 1];
            }
            return;
        }

        set.insert(level);
        sub_set(n, level + 1, set);
        set.erase(level);
        sub_set(n, level + 1, set);
    }
};

#endif //LEETCODE_1617_H
