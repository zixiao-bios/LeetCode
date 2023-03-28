#ifndef LEETCODE_1143_2_H
#define LEETCODE_1143_2_H

/**
 * dp[i][j]: text1 的 [0, i) 子串与 text2 的 [0, j) 子串的最长公共子序列长度
 *
 * dp[i][j] = dp[i-1][j-1] + 1              , text1[i-1] == text2[j-1]
 *          = max(dp[i-1][j], dp[i][j-1])   , else
 *
 * dp[i][0] = dp[0][j] = 0
 */

#include <vector>

using std::string;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        std::vector dp = std::vector(m + 1, std::vector(n + 1, 0));

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

#endif //LEETCODE_1143_2_H
