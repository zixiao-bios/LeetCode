#ifndef LEETCODE_0695_2_H
#define LEETCODE_0695_2_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        stack<pair<int, int>> stack;
        int ans = 0;

        vector<pair<int, int>> direction = {{1,  0},
                                            {-1, 0},
                                            {0,  1},
                                            {0,  -1}};

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                int i = y, j = x;
                int area = 0;

                while (true) {
                    if (!visited[i][j] and grid[i][j] == 1) {
                        visited[i][j] = true;
                        ++area;

                        for (auto &each: direction) {
                            pair<int, int> new_pos = {i + each.first, j + each.second};
                            if (new_pos.first >= 0 and new_pos.first < m and new_pos.second >= 0 and new_pos.second < n) {
                                stack.push(new_pos);
                            }
                        }
                    }

                    if (stack.empty()) {
                        break;
                    } else {
                        auto pos = stack.top();
                        stack.pop();
                        i = pos.first, j = pos.second;
                    }
                }

                ans = max(ans, area);
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0695_2_H
