#ifndef LEETCODE_0037_H
#define LEETCODE_0037_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool row[9][9], col[9][9], cube[3][3][9];
    bool find = false;
    vector<pair<int, int>> space;

    void solveSudoku(vector<vector<char>> &board) {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(cube, false, sizeof(cube));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    space.emplace_back(i, j);
                } else {
                    int v = board[i][j] - '0' - 1;
                    row[i][v] = true;
                    col[j][v] = true;
                    cube[i / 3][j / 3][v] = true;
                }
            }
        }

        backtrace(board, 0);
    }

    void backtrace(vector<vector<char>> &board, int pos) {
        if (pos == space.size()) {
            find = true;
            return;
        }

        int i = space[pos].first;
        int j = space[pos].second;

        for (int v = 0; v < 9; ++v) {
            if (!row[i][v] and !col[j][v] and !cube[i / 3][j / 3][v]) {
                if (find) {
                    return;
                }

                // 都没用过，可以填入
                row[i][v] = true;
                col[j][v] = true;
                cube[i / 3][j / 3][v] = true;
                board[i][j] = v + 1 + '0';

                backtrace(board, pos + 1);

                row[i][v] = false;
                col[j][v] = false;
                cube[i / 3][j / 3][v] = false;
            }
        }
    }
};

#endif //LEETCODE_0037_H
