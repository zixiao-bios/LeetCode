#ifndef LEETCODE_1223_H
#define LEETCODE_1223_H

/**
 * dp[i][j][k]: 投第i次，以j点数结尾，结尾的j点数连续出现k次时，序列的数量
 *
 * dp[i][j][k] = dp[i-1][j][k-1]    1 < k <= rollMax[j]
 *             = sum(dp[i-1][p])    k == 1, p != j
 *             = 0                  k > rollMax[j]
 *
 * dp[1][j][1] = 1
 * dp[1][j][k] = 0, k>1
 */

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    [[nodiscard]] int sum_with_mod(const vector<int> &a) const {
        int ans = 0;
        for (auto &each: a) {
            ans += each;
            ans %= mod;
        }
        return ans;
    }

    int dieSimulator(int n, vector<int> &rollMax) {
        vector dp(n + 1, vector(6, vector<int>(16)));

        for (int j = 0; j < 6; ++j) {
            dp[1][j][1] = 1;
        }

        for (int i = 2; i < n + 1; ++i) {
            for (int j = 0; j < 6; ++j) {

                // k = 1
                for (int jj = 0; jj < 6; ++jj) {
                    if (jj != j) {
                        dp[i][j][1] += sum_with_mod(dp[i - 1][jj]);
                        dp[i][j][1] %= mod;
                    }
                }

                // k > 1
                for (int k = 2; k <= rollMax[j]; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k - 1];
                }
            }
        }

        int ans = 0;
        for (int j = 0; j < 6; ++j) {
            ans += sum_with_mod(dp[n][j]);
            ans %= mod;
        }
        return ans;
    }
};

#endif //LEETCODE_1223_H
