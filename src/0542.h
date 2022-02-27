#ifndef LEETCODE_0542_H
#define LEETCODE_0542_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> direction = {{0,  1},
                                     {0,  -1},
                                     {1,  0},
                                     {-1, 0}};
    int m,n;

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> queue;
        vector<vector<int>> dis(m, vector<int>(n, -1));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    queue.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }

        while (!queue.empty()) {
            pair<int, int> pos = queue.front();
            queue.pop();

            for (auto &each: direction) {
                pair<int, int> newPos = {pos.first + each.first, pos.second + each.second};

                if (newPos.first >= 0 and newPos.first < m and newPos.second >= 0 and newPos.second < n and
                    dis[newPos.first][newPos.second] == -1) {
                    dis[newPos.first][newPos.second] = dis[pos.first][pos.second] + 1;
                    queue.push(newPos);
                }
            }
        }

        return dis;
    }
};

#endif //LEETCODE_0542_H
