#ifndef LEETCODE_0072_H
#define LEETCODE_0072_H

#include <vector>

using namespace std;

/**
 * dp[i][j]: s1 的前 i 个字符到 s2 的前 j 个字符的编辑距离
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = 0; i < m + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else {
                    if (word1[i - 1] == word2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                    }
                }
            }
        }

        return dp[m][n];
    }
};

#endif //LEETCODE_0072_H
