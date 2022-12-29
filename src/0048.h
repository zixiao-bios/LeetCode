#ifndef LEETCODE_0048_H
#define LEETCODE_0048_H

#include <vector>

using namespace std;

class Solution {
public:
    int n;

    void rotate(vector<vector<int>> &matrix) {
        n = matrix.size();
        int level = 0;
        while (rotate_level(matrix, level)) {
            ++level;
        }
    }

    bool rotate_level(vector<vector<int>> &matrix, int level) {
        int step = n - 2 * level - 1;
        if (step < 1) {
            return false;
        }

        vector<pair<int, int>> anchor = {{level,         level},
                                         {level,         n - level - 1},
                                         {n - level - 1, n - level - 1},
                                         {n - level - 1, level}};

        for (int i = 0; i < step; ++i) {
            swap(matrix[anchor[0].first][anchor[0].second + i], matrix[anchor[1].first + i][anchor[1].second]);
            swap(matrix[anchor[2].first][anchor[2].second - i], matrix[anchor[3].first - i][anchor[3].second]);
            swap(matrix[anchor[0].first][anchor[0].second + i], matrix[anchor[2].first][anchor[2].second - i]);
        }

        return true;
    }
};

#endif //LEETCODE_0048_H
