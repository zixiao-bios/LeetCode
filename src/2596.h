#ifndef LEETCODE_2596_H
#define LEETCODE_2596_H

#include <vector>

using std::vector;

class Solution {
public:
    using pos_t = std::pair<int, int>;

    bool checkValidGrid(vector<vector<int>> &grid) {
        if (grid[0][0] != 0) {
            return false;
        }

        int n = grid.size();
        vector<pos_t> step_to_pos(n * n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                step_to_pos[grid[i][j]] = {i, j};
            }
        }

        pos_t current_pos = step_to_pos.at(0);
        for (int i = 1; i < n * n; ++i) {
            if (is_valid(current_pos, step_to_pos[i])) {
                current_pos = step_to_pos[i];
            } else {
                return false;
            }
        }
        return true;
    }

    static bool is_valid(const pos_t &current_pos, const pos_t &next_pos) {
        int row_move = std::abs(current_pos.first - next_pos.first);
        int col_move = std::abs(current_pos.second - next_pos.second);
        return (row_move == 2 and col_move == 1) or (row_move == 1 and col_move == 2);
    }
};

#endif //LEETCODE_2596_H
