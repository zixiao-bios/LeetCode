#ifndef LEETCODE_0036_H
#define LEETCODE_0036_H

#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    bool check(const function<char(int, int)> &get, int id) {
        vector<bool> use(9, false);

        for (int i = 0; i < 9; ++i) {
            char ch = get(id, i);

            if (ch == '.') {
                continue;
            }

            int value = ch - 49;
            if (use[value]) {
                return false;
            } else {
                use[value] = true;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        auto get_row = [&board](int id, int i) {
            return board[id][i];
        };

        auto get_col = [&board](int id, int i) {
            return board[i][id];
        };

        auto get_cube = [&board](int id, int i) {
            int id2i[] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
            int id2j[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};

            return board[3 * id2i[id] + id2i[i]][3 * id2j[id] + id2j[i]];
        };

        for (int i = 0; i < 9; ++i) {
            if (check(get_row, i) and check(get_col, i) and check(get_cube, i)) {
                continue;
            }
            return false;
        }

        return true;
    }
};

#endif //LEETCODE_0036_H
