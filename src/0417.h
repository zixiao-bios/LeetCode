#ifndef LEETCODE_0417_H
#define LEETCODE_0417_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> direction = {{0,  -1},
                                     {0,  1},
                                     {-1, 0},
                                     {1,  0}};

    int m, n;

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        m = heights.size(), n = heights[0].size();

        vector<vector<bool>> reachA(m, vector<bool>(n, false));
        vector<vector<bool>> reachB(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            dfs(heights, reachA, i, 0);
            dfs(heights, reachB, i, n - 1);
        }

        for (int i = 0; i < n; ++i) {
            dfs(heights, reachA, 0, i);
            dfs(heights, reachB, m - 1, i);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (reachA[i][j] and reachB[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &reach, int i, int j) {
        reach[i][j] = true;

        int x, y;
        for (auto &each: direction) {
            x = i + each[0], y = j + each[1];
            if (x >= 0 and x < m and y >= 0 and y < n and heights[x][y] >= heights[i][j] and !reach[x][y]) {
                dfs(heights, reach, x, y);
            }
        }
    }
};

#endif //LEETCODE_0417_H
