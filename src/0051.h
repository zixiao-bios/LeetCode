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

        for (int j = 0; j < n; ++j) {
            if (column[j]) {
                continue;
            }

            int left_idx = row + j;
            if (left[left_idx]) {
                continue;
            }

            int right_idx = row - j + n - 1;
            if (right[right_idx]) {
                continue;
            }

            // find a place
            column[j] = true;
            left[left_idx] = true;
            right[right_idx] = true;
            board[row][j] = 'Q';

            backtracking(row + 1, n);

            column[j] = false;
            left[left_idx] = false;
            right[right_idx] = false;
            board[row][j] = '.';
        }
    }
};

#endif //LEETCODE_0051_H
