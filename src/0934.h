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

    int n;

    bool out_range(int i, int j) {
        return i < 0 or i >= n or j < 0 or j >= n;
    }

    int shortestBridge(vector<vector<int>> &grid) {
        n = grid.size();

        // bfs to find island 1
        queue<pair<int, int>> queue, island_1;
        bool find = false;

        for (int i = 0; i < n; ++i) {
            if (find) {
                break;
            }

            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    find = true;

                    // bfs
                    queue.push({i, j});
                    island_1.push({i, j});
                    grid[i][j] = 2;

                    while (!queue.empty()) {
                        int ii = queue.front().first;
                        int jj = queue.front().second;
                        queue.pop();

                        for (auto &each: direction) {
                            int x = ii + each.first;
                            int y = jj + each.second;

                            if (out_range(x, y)) {
                                continue;
                            }

                            if (grid[x][y] == 1) {
                                grid[x][y] = 2;
                                queue.push({x, y});
                                island_1.push({x, y});
                            }
                        }
                    }

                    break;
                }
            }
        }

        // bfs island 1 to find island 2
        int steps = 0;

        while (true) {
            int num = island_1.size();
            for (int a = 0; a < num; ++a) {
                int i = island_1.front().first;
                int j = island_1.front().second;
                island_1.pop();

                for (auto &each: direction) {
                    int x = i + each.first;
                    int y = j + each.second;

                    if (out_range(x, y)) {
                        continue;
                    }

                    switch (grid[x][y]) {
                        case 0:
                            grid[x][y] = 2;
                            island_1.push({x, y});
                            break;
                        case 1:
                            // find island 2
                            return steps;
                    }
                }
            }
            ++steps;
        }
    }
};

#endif //LEETCODE_0934_H
