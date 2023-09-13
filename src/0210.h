#ifndef LEETCODE_0210_H
#define LEETCODE_0210_H

#include <vector>
#include <queue>

using std::vector;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector graph = vector(numCourses, std::vector<int>());
        vector in_degree = vector<int>(numCourses);

        for (const auto &each: prerequisites) {
            graph[each[1]].push_back(each[0]);
            ++in_degree[each[0]];
        }

        std::queue<int> can_learn;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                can_learn.push(i);
            }
        }

        vector<int> ans;
        ans.reserve(numCourses);
        while (!can_learn.empty()) {
            int course = can_learn.front();
            can_learn.pop();
            ans.push_back(course);

            for (const auto &child: graph[course]) {
                --in_degree[child];
                if (in_degree[child] == 0) {
                    can_learn.push(child);
                }
            }
        }

        if (ans.size() == numCourses) {
            return ans;
        } else {
            return {};
        }
    }
};

#endif //LEETCODE_0210_H
