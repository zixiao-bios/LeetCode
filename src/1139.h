#ifndef LEETCODE_1139_H
#define LEETCODE_1139_H

/**
 * right[i][j]: grid[i][j] 及其右侧连续的 1 的长度
 * down[i][j]: grid[i][j] 及其下方连续的 1 的长度
 */

#include <vector>

using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector right = vector(m, vector(n, 0));
        vector down = vector(m, vector(n, 0));
        for (int i = 0; i < m; ++i) {
            right[i][n - 1] = grid[i][n - 1];
            for (int j = n - 2; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    right[i][j] = right[i][j + 1] + 1;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            down[m - 1][j] = grid[m - 1][j];
            for (int i = m - 2; i >= 0; --i) {
                if (grid[i][j] == 1) {
                    down[i][j] = down[i + 1][j] + 1;
                }
            }
        }

        int max_len = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int l = min(m - i, n - j); l > 0; --l) {
                    if (right[i][j] >= l and down[i][j] >= l and
                        right[i + l - 1][j] >= l and down[i][j + l - 1] >= l) {
                        max_len = max(max_len, l);
                        break;
                    }
                }
            }
        }
        return max_len * max_len;
    }
};

#endif //LEETCODE_1139_H
