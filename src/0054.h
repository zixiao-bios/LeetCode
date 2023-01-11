#ifndef LEETCODE_0054_H
#define LEETCODE_0054_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> direction = {
            {0, 1, 1},
            {1, 0, 0},
            {0, -1, 0},
            {-1, 0, -1}
    };
    vector<int> ans;

    bool walk(const vector<vector<int>> &matrix, vector<int> dir, int steps, int &i, int &j) {
        if (steps <= 0) {
            return false;
        }

        for (int k = 0; k < steps; ++k) {
            i += dir[0], j += dir[1];
            ans.push_back(matrix[i][j]);
        }

        return true;
    }

    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row_n = m - 1;
        int col_n = n - 1;
        int step_n = (min(m, n) + 1) / 2;

        int i = 0, j = -1;
        for (int k = 0; k < step_n; ++k) {
            for (auto &dir: direction) {
                if (dir[0] == 0) {
                    // move horizontal
                    if (!walk(matrix, dir, col_n + dir[2], i, j)) {
                        break;
                    }
                } else {
                    // move vertical
                    if (!walk(matrix, dir, row_n + dir[2], i, j)) {
                        break;
                    }
                }
            }

            row_n -= 2, col_n -= 2;
        }

        return ans;
    }
};

#endif //LEETCODE_0054_H
