#ifndef LEETCODE_1140_H
#define LEETCODE_1140_H

/**
 * dp[i][j]：从索引为i的石头开始拿，且M=j时，此时该取石头的人能获取的最大石头数量
 *
 * dp[i][j] = sum(piles[i:n-1])                                   , 2j >= n - i 即能拿走剩余全部石头
 *          = sum(piles[i:n-1]) - min(dp[i+x][max(x,j)]) x=[1,2j]   , else
 *
 * dp[n-1][j] = piles[n-1]
 */

#include <vector>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int> &piles) {
        int n = piles.size();
        int max_m = (n + 1) / 2;
        vector dp(n, vector(max_m + 1, 0));

        vector suffix_sum(n, piles[n - 1]); // suffix_sum[x] = sum(plies[i]), i=[x, n-1]
        for (int i = n - 2; i >= 0; --i) {
            suffix_sum[i] = suffix_sum[i + 1] + piles[i];
        }

        for (int j = 1; j <= max_m; ++j) {
            dp[n - 1][j] = piles[n - 1];
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 1; j <= max_m; ++j) {
                if (2 * j >= n - i) {
                    dp[i][j] = suffix_sum[i];
                } else {
                    int min_num = INT32_MAX;
                    for (int x = 1; x <= 2 * j; ++x) {
                        if (i + x >= n or x > max_m) {
                            break;
                        }
                        min_num = min(min_num, dp[i + x][max(x, j)]);
                    }
                    dp[i][j] = suffix_sum[i] - min_num;
                }
            }
        }

        return dp[0][1];
    }
};

#endif //LEETCODE_1140_H
