#ifndef LEETCODE_1462_H
#define LEETCODE_1462_H

#include <vector>
#include <queue>

using std::vector;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
        vector graph = vector(numCourses, vector<int>());
        vector in_degree = vector<int>(numCourses, 0);

        for (const auto &each: prerequisites) {
            graph[each[0]].push_back(each[1]);
            ++in_degree[each[1]];
        }

        std::queue<int> can_learn;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                can_learn.push(i);
            }
        }

        vector is_pre = vector(numCourses, vector(numCourses, false));
        while (!can_learn.empty()) {
            int cur = can_learn.front();
            can_learn.pop();

            for (const auto &child: graph[cur]) {
                --in_degree[child];
                if (in_degree[child] == 0) {
                    can_learn.push(child);
                }

                is_pre[cur][child] = true;
                for (int i = 0; i < numCourses; ++i) {
                    is_pre[i][child] = is_pre[i][child] or is_pre[i][cur];
                }
            }
        }

        vector<bool> ans;
        for (const auto &each: queries) {
            ans.push_back(is_pre[each[0]][each[1]]);
        }
        return ans;
    }
};

#endif //LEETCODE_1462_H
