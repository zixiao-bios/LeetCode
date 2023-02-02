#ifndef LEETCODE_1129_H
#define LEETCODE_1129_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> find_next_nodes(const vector<vector<int>> &edges, int node) {
        vector<int> node_list;
        for (auto &edge: edges) {
            if (edge[0] == node) {
                node_list.push_back(edge[1]);
            }
        }
        return node_list;
    }

    void find_path(vector<vector<int>> &dis, vector<vector<int>> &redEdges,
                   vector<vector<int>> &blueEdges, bool red) {
        queue<int> queue;
        vector<int> node_list;
        int steps = 0;
        queue.push(0);
        queue.push(-1);
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();

            if (node == -1) {
                ++steps;
                red = !red;
                if (!queue.empty()) {
                    queue.push(-1);
                }
                continue;
            }

            if (steps < dis[node][red]) {
                dis[node][red] = steps;
            } else {
                continue;
            }

            node_list = find_next_nodes(red ? redEdges : blueEdges, node);

            for (auto &next_node: node_list) {
                queue.push(next_node);
            }
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
        // 当轮到从红色/蓝色边出发时，到node的距离
        vector<vector<int32_t>> dis(n, vector<int32_t>(2, INT32_MAX));

        find_path(dis, redEdges, blueEdges, true);
        find_path(dis, redEdges, blueEdges, false);

        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            ans[i] = min(dis[i][0], dis[i][1]);
            if (ans[i] == INT32_MAX) {
                ans[i] = -1;
            }
        }

        return ans;
    }
};

#endif //LEETCODE_1129_H
