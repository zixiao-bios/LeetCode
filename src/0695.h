#ifndef LEETCODE_0695_H
#define LEETCODE_0695_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() or grid[0].empty()) {
            return 0;
        }

        int ans = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }

    int dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = 0;

        return 1 + dfs(grid, i, j + 1) + dfs(grid, i, j - 1) + dfs(grid, i + 1, j) + dfs(grid, i - 1, j);
    }
};

#endif //LEETCODE_0695_H
