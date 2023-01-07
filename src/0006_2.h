#ifndef LEETCODE_0006_2_H
#define LEETCODE_0006_2_H

#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int t = 2 * numRows - 2;
        int numCols = (s.size() / t + 1) * (numRows - 1);
        vector<vector<char>> grid(numRows, vector<char>(numCols, ' '));

        int i = 0, j = 0;
        bool down = true;
        for (auto &ch: s) {
            grid[i][j] = ch;

            if (down) {
                if (i == numRows - 1) {
                    down = false;
                    --i, ++j;
                } else {
                    ++i;
                }
            } else {
                if (i == 0) {
                    down = true;
                    ++i;
                } else {
                    --i, ++j;
                }
            }
        }

        string ans;
        for (int k = 0; k < numRows; ++k) {
            for (int l = 0; l < numCols; ++l) {
                if (grid[k][l] != ' ') {
                    ans += grid[k][l];
                }
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0006_2_H
