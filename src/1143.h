#ifndef LEETCODE_1143_H
#define LEETCODE_1143_H

#include <vector>

using namespace std;

/**
 * dp[i][j]: s1 的前 i 个字符与 s2 的前 j 个字符的最长公共子序列
 *
 * if (s1[i-1] == s2[j-1])
 *      dp[i][j] = dp[i-1][j-1] + 1
 * else
 *      dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 *
 * dp[0][j] = dp[i][0] = 0
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        auto *dp1 = new vector<int>(n + 1, 0);
        auto *dp2 = new vector<int>(n + 1, 0);

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp2->at(j) = dp1->at(j - 1) + 1;
                } else {
                    dp2->at(j) = max(dp1->at(j), dp2->at(j - 1));
                }
            }
            swap(dp1, dp2);
        }

        return dp1->at(n);
    }
};

#endif //LEETCODE_1143_H
