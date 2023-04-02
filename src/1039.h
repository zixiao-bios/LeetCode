#ifndef LEETCODE_1039_H
#define LEETCODE_1039_H

/**
 * find[i][j]: 从 i 节点顺时针到 j 节点，再从 j 节点直接连到 i 节点，上述边围成的多边形的最小的分
 *
 * dp[i][j] = min(dp[i][k] + find[k][j] + v[i] * v[j] * v[k]) , i+1 <= k <= j-1
 *
 * find[i][i+1] = 0
 */

#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> mem;
    vector<int> val;

    int minScoreTriangulation(vector<int> &values) {
        int n = values.size();
        vector dp = vector(n, vector(n, -1));
        mem = dp;
        val = values;
        return find(0, n - 1);
    }

    int find(int i, int j) {
        if (mem[i][j] != -1) {
            return mem[i][j];
        }

        if (j == i + 1) {
            return 0;
        }

        int min = INT_MAX;
        for (int k = i + 1; k <= j - 1; ++k) {
            min = std::min(min, find(i, k) + find(k, j) + val[i] * val[k] * val[j]);
        }
        mem[i][j] = min;
        return mem[i][j];
    }
};

#endif //LEETCODE_1039_H
