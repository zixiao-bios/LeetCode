#ifndef LEETCODE_0695_H
#define LEETCODE_0695_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> direction = {{0,  1},
                                        {0,  -1},
                                        {1,  0},
                                        {-1, 0}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size(), false));

        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                ans = max(ans, dfs(grid, flag, i, j));
            }
        }

        return ans;
    }

    int dfs(const vector<vector<int>> &grid, vector<vector<bool>> &flag, int i, int j) {
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size()) {
            return 0;
        }

        if (flag[i][j] or grid[i][j] == 0) {
            return 0;
        }

        flag[i][j] = true;
        int area = 0;
        for (auto &each: direction) {
            area += dfs(grid, flag, i + each.first, j + each.second);
        }
        return area + 1;
    }
};

#endif //LEETCODE_0695_H
