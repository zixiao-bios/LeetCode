#ifndef LEETCODE_1091_H
#define LEETCODE_1091_H

#include <vector>
#include <queue>

using std::vector;

class Solution {
public:
    vector<std::pair<int, int>> neighbor = {{0,  1},
                                            {0,  -1},
                                            {1,  0},
                                            {-1, 0},
                                            {1,  1},
                                            {1,  -1},
                                            {-1, 1},
                                            {-1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        auto n = grid.size();
        std::queue<std::pair<int, int>> queue;
        int step = 0;

        if (grid[0][0] == 1) {
            return -1;
        }
        queue.emplace(0, 0);
        queue.emplace(-1, -1);

        while (not queue.empty()) {
            int x = queue.front().first;
            int y = queue.front().second;
            queue.pop();

            if (x == -1) {
                ++step;
                if (not queue.empty()) {
                    queue.emplace(-1, -1);
                }
                continue;
            }

            if (x == n - 1 and y == n - 1) {
                ++step;
                return step;
            }

            if (grid[x][y] == 0) {
                grid[x][y] = 2;
                for (const auto &each: neighbor) {
                    int xx = x + each.first;
                    int yy = y + each.second;
                    if (xx >= 0 and xx < n and yy >= 0 and yy < n and grid[xx][yy] == 0) {
                        queue.emplace(xx, yy);
                    }
                }
            }
        }

        return -1;
    }
};

#endif //LEETCODE_1091_H
