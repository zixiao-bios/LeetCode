#ifndef LEETCODE_1444_H
#define LEETCODE_1444_H

/**
 * 每个状态可以用剩余披萨的左上角坐标表示
 *
 * num[i][j][p]: 将以 pizza[i][j] 作为左上角的子披萨切成 p 份，且每份至少一个苹果的方案数
 *
 * num[i][j][p] = sum(num[ix][j][p-1]) + sum(num[i][jx][p-1])   , 被切掉的部分至少有一个苹果
 */

#include <vector>

class Solution {
public:
    int mod = 1e9 + 7;
    size_t m, n;
    std::vector<std::vector<std::vector<int>>> num;

    int ways(std::vector<std::string> &pizza, int k) {
        m = pizza.size();
        n = pizza[0].size();
        num = std::vector(m, std::vector(n, std::vector(k + 1, -1)));
        return dfs(pizza, 0, 0, k);
    }

    // 以 pizza[r][c] 开始的行或列是否含有苹果
    bool has_apple(const std::vector<std::string> &pizza, int r, int c, bool row) const {
        if (row) {
            for (int j = c; j < n; ++j) {
                if (pizza[r][j] == 'A') {
                    return true;
                }
            }
            return false;
        } else {
            for (int i = r; i < m; ++i) {
                if (pizza[i][c] == 'A') {
                    return true;
                }
            }
            return false;
        }
    }

    int dfs(const std::vector<std::string> &pizza, int r, int c, int p) {
        if (r < 0 or r >= m or c < 0 or c >= n) {
            return 0;
        } else if (num[r][c][p] != -1) {
            return num[r][c][p];
        }

        // 当前状态在有效范围内，且未计算，开始计算

        // 最后一步，直接检查当前子披萨有无苹果
        if (p == 1) {
            for (int i = r; i < m; ++i) {
                if (has_apple(pizza, i, c, true)) {
                    num[r][c][p] = 1;
                    return num[r][c][p];
                }
            }
            num[r][c][p] = 0;
            return num[r][c][p];
        }

        // 切披萨
        int res = 0;

        // 横着切，i 表示剩余披萨以第 i 行开始
        bool flag = false;
        for (int i = r + 1; i < m; ++i) {
            if (flag) {
                res += dfs(pizza, i, c, p - 1);
                res %= mod;
            } else {
                if (has_apple(pizza, i - 1, c, true)) {
                    flag = true;
                    res += dfs(pizza, i, c, p - 1);
                    res %= mod;
                }
            }
        }

        // 竖着切，j 表示剩余披萨以第 j 列开始
        flag = false;
        for (int j = c + 1; j < n; ++j) {
            if (flag) {
                res += dfs(pizza, r, j, p - 1);
                res %= mod;
            } else {
                if (has_apple(pizza, r, j - 1, false)) {
                    flag = true;
                    res += dfs(pizza, r, j, p - 1);
                    res %= mod;
                }
            }
        }

        num[r][c][p] = res;
        return num[r][c][p];
    }
};

#endif //LEETCODE_1444_H
