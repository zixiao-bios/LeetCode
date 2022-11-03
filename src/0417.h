#ifndef LEETCODE_0417_H
#define LEETCODE_0417_H

#include <vector>

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

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> reachA(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(heights, reachA, i, 0);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, reachA, 0, j);
        }

        vector<vector<bool>> reachB(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(heights, reachB, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, reachB, m - 1, j);
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

    void dfs(const vector<vector<int>> &heights, vector<vector<bool>> &reach, int i, int j) {
        if (reach[i][j]) {
            return;
        }
        reach[i][j] = true;

        for (auto &each: direction) {
            int ii = i + each.first, jj = j + each.second;
            if (!outOfBounds(ii, jj) and heights[ii][jj] >= heights[i][j]) {
                dfs(heights, reach, ii, jj);
            }
        }
    }
};

#endif //LEETCODE_0417_H
