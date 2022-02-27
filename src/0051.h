#ifndef LEETCODE_0051_H
#define LEETCODE_0051_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    vector<bool> column, left, right;

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        column = vector<bool>(n, false);
        left = vector<bool>(2 * n - 1, false);
        right = vector<bool>(2 * n - 1, false);

        backtracking(0, n);

        return ans;
    }

    void backtracking(int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (column[i] or left[i + row] or right[i - row + n - 1]) {
                continue;
            }

            column[i] = true, left[i + row] = true, right[i - row + n - 1] = true;
            board[row][i] = 'Q';

            backtracking(row + 1, n);

            column[i] = false, left[i + row] = false, right[i - row + n - 1] = false;
            board[row][i] = '.';
        }
    }
};

#endif //LEETCODE_0051_H
