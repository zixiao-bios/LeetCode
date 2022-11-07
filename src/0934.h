#ifndef LEETCODE_0934_H
#define LEETCODE_0934_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> direction = {{1,  0},
                                        {-1, 0},
                                        {0,  1},
                                        {0,  -1}};

    int m, n;

    bool outOfBounds(int i, int j) {
        return i < 0 or i >= m or j < 0 or j >= n;
    }

    int shortestBridge(vector<vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;

        // find island a
        bool find = false;
        for (int i = 0; i < m; ++i) {
            if (find) {
                break;
            }

            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) {
                    continue;
                }

                find = true;
                points.push({i, j});

                queue<pair<int, int>> bfs;
                bfs.push({i, j});
                grid[i][j] = -1;
                while (!bfs.empty()) {
                    for (auto &each: direction) {
                        int x = bfs.front().first + each.first;
                        int y = bfs.front().second + each.second;
                        if (outOfBounds(x, y)) {
                            continue;
                        }

                        if (grid[x][y] == 1) {
                            grid[x][y] = -1;
                            bfs.push({x, y});
                            points.push({x, y});
                        }
                    }
                    bfs.pop();
                }
                break;
            }
        }

        // find island b
        int length = 0;
        while (true) {
            int num = points.size();
            for (int i = 0; i < num; ++i) {
                for (auto &each: direction) {
                    int x = points.front().first + each.first;
                    int y = points.front().second + each.second;
                    if (outOfBounds(x, y)) {
                        continue;
                    }

                    switch (grid[x][y]) {
                        case 1:
                            return length;
                        case 0:
                            grid[x][y] = -1;
                            points.push({x, y});
                    }
                }
                points.pop();
            }
            ++length;
        }
    }
};

#endif //LEETCODE_0934_H
