#ifndef LEETCODE_2397_H
#define LEETCODE_2397_H

#include <vector>
#include <unordered_set>

using std::vector;

class Solution {
public:
    size_t m, n;
    int num;
    int ans = -1;

    static int cover_row_num(const vector<vector<int>> &matrix, const vector<int> &select) {
        int cover_num = 0;

        std::unordered_set<int> set;
        for (auto &each: select) {
            set.insert(each);
        }

        for (auto &row: matrix) {
            bool cover = true;
            for (int j = 0; j < row.size(); ++j) {
                if (row[j] == 1 and not set.contains(j)) {
                    cover = false;
                    break;
                }
            }
            cover_num += cover;
        }
        return cover_num;
    }

    int maximumRows(vector<vector<int>> &matrix, int numSelect) {
        this->m = matrix.size();
        this->n = matrix[0].size();
        this->num = numSelect;

        vector<int> select(numSelect, -1);
        backtrace(0, select, matrix);

        return this->ans;
    }

    void backtrace(int level, vector<int> &select, const vector<vector<int>> &matrix) {
        if (level == this->num) {
            ans = std::max(ans, Solution::cover_row_num(matrix, select));
            return;
        }

        int start;
        if (level == 0) {
            start = 0;
        } else {
            start = select[level - 1] + 1;
        }

        for (int j = start; j < n; ++j) {
            select[level] = j;
            backtrace(level + 1, select, matrix);
        }
    }
};

#endif //LEETCODE_2397_H
