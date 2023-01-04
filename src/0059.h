#ifndef LEETCODE_0059_H
#define LEETCODE_0059_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> direction = {{0,  1},
                                        {1,  0},
                                        {0,  -1},
                                        {-1, 0}};

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n, 0));
        int v = 1;
        int i = 0, j = -1;

        while (true) {
            for (auto &each: direction) {
                while (true) {
                    int ii = i + each.first;
                    int jj = j + each.second;
                    if (ii >= 0 and jj >= 0 and ii < n and jj < n and m[ii][jj] == 0) {
                        i = ii, j = jj;
                        m[i][j] = v;
                        ++v;
                    } else {
                        break;
                    }
                }
            }

            if (v == n * n + 1) {
                break;
            }
        }

        return m;
    }
};

#endif //LEETCODE_0059_H
