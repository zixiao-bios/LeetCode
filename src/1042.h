#ifndef LEETCODE_1042_H
#define LEETCODE_1042_H

#include <vector>
#include <queue>

using std::vector;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
        vector graph = vector(n, vector<int>{});
        vector garden = vector(n, 0);

        for (const auto &path: paths) {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }

        for (int i = 0; i < n; ++i) {
            vector used(5, false);
            for (const auto &nei: graph[i]) {
                used[garden[nei]] = true;
            }
            int color = 1;
            while (used[color]) {
                ++color;
            }
            garden[i] = color;
        }

        return garden;
    }
};

#endif //LEETCODE_1042_H
