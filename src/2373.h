#ifndef LEETCODE_2373_H
#define LEETCODE_2373_H

#include <vector>

using std::vector;

class Solution {
public:
    int find_max(const vector<vector<int>> &grid, int i, int j) {
        int res = INT32_MIN;
        for (int k = -1; k < 2; ++k) {
            for (int l = -1; l < 2; ++l) {
                res = std::max(res, grid[i + k][l + j]);
            }
        }
        return res;
    }

    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        auto n = grid.size();
        vector ans = vector(n - 2, vector(n - 2, 0));
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                ans[i - 1][j - 1] = find_max(grid, i, j);
            }
        }
        return ans;
    }
};

#endif //LEETCODE_2373_H
