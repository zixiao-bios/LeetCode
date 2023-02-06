#ifndef LEETCODE_1210_H
#define LEETCODE_1210_H

#include <vector>
#include <queue>

class Solution {
public:
    int minimumMoves(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<std::vector<int>>> dis(n, std::vector<std::vector<int>>(n, std::vector<int>(2, INT32_MAX)));
        std::queue<std::vector<int>> queue;

        dis[0][0][0] = 0;
        queue.push({0, 0, 0});

        while (!queue.empty()) {
            int i = queue.front()[0];
            int j = queue.front()[1];
            int r = queue.front()[2];
            queue.pop();

            int ih = i + r;
            int jh = j + (1 - r);

            // right
            if (jh + 1 < n and grid[i][j + 1] == 0 and grid[ih][jh + 1] == 0) {
                if (dis[i][j][r] + 1 < dis[i][j + 1][r]) {
                    dis[i][j + 1][r] = dis[i][j][r] + 1;
                    queue.push({i, j + 1, r});
                }
            }

            // down
            if (ih + 1 < n and grid[i + 1][j] == 0 and grid[ih + 1][jh] == 0) {
                if (dis[i][j][r] + 1 < dis[i + 1][j][r]) {
                    dis[i + 1][j][r] = dis[i][j][r] + 1;
                    queue.push({i + 1, j, r});
                }
            }

            // rotate
            if (r == 0 and i + 1 < n and grid[i + 1][j] == 0 and grid[ih + 1][jh] == 0) {
                if (dis[i][j][r] + 1 < dis[i][j][1]) {
                    dis[i][j][1] = dis[i][j][r] + 1;
                    queue.push({i, j, 1});
                }
            } else if (r == 1 and j + 1 < n and grid[i][j + 1] == 0 and grid[ih][jh + 1] == 0) {
                if (dis[i][j][r] + 1 < dis[i][j][0]) {
                    dis[i][j][0] = dis[i][j][r] + 1;
                    queue.push({i, j, 0});
                }
            }
        }

        return dis[n - 1][n - 2][0] == INT32_MAX ? -1 : dis[n - 1][n - 2][0];
    }
};

#endif //LEETCODE_1210_H
