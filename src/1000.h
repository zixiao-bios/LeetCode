#ifndef LEETCODE_1000_H
#define LEETCODE_1000_H

/**
 * dp[i][j][k]: 把索引为 [i, j] 堆石头合成 k 堆石头的最小代价
 *
 * 每次合并导致减少 s 堆 (s = x-1)
 * dp[i][j][1] = dp[i][j][x] + sum(dp[i, j])
 * dp[i][j][k] = min( dp[i][i+p*s][1] + dp[i+p*s+1][j][k-1] )   , p = 0,1,2... and i+p*s+1 <= j
 *
 * dp[i][i][1] = 0
 */

#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<vector<int>>> mem;
    vector<int> prefix_sum;
    int x;

    int sum(int i, int j) {
        return prefix_sum[j] - prefix_sum[i];
    }

    int mergeStones(vector<int> &stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }

        x = k;
        mem = vector(n, vector(n, vector(k + 1, -1)));
        prefix_sum = vector(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + stones[i - 1];
        }
        return find(0, n - 1, 1);
    }

    int find(int i, int j, int k) {
        if (mem[i][j][k] != -1) {
            return mem[i][j][k];
        }

        if (i == j and k == 1) {
            mem[i][j][k] = 0;
            return mem[i][j][k];
        }

        if (j - i + 1 < k) {
            mem[i][j][k] = -2;
            return mem[i][j][k];
        }

        if (k == 1) {
            mem[i][j][k] = find(i, j, x) + sum(i, j + 1);
        } else {
            int min = INT32_MAX;
            for (int p = 0; i + p * (x - 1) + 1 <= j; ++p) {
                int t1 = find(i, i + p * (x - 1), 1);
                int t2 = find(i + p * (x - 1) + 1, j, k - 1);
                if (t1 != -2 and t2 != -2) {
                    min = std::min(min, t1 + t2);
                }
            }
            mem[i][j][k] = min;
        }
        return mem[i][j][k];
    }
};

#endif //LEETCODE_1000_H
