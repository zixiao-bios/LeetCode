#ifndef LEETCODE_1092_H
#define LEETCODE_1092_H

/**
 * 先求出两个字符串的最长公共子序列的元素索引，然后遍历两字符串，在完全利用最长公共子序列的前提下，生成满足题意的字符串
 *
 * dp[i][j]: s1 的 [0, i) 子串和 s2 的 [0, j) 子串的最长公共子序列长度
 *
 * dp[i][j] = dp[i-1][j-1] + 1              , s1[i-1] == s2[j-1]
 *          = max(dp[i][j-1], dp[i-1][j])   , else
 *
 * dp[i][0] = dp[0][j] = 0
 *
 * mark[i][j] 用于记录 dp[i][j] 的上一个状态
 * mark[i][j] = 0   , dp[i][j] = dp[i-1][j-1] + 1
 *            = 1   , dp[i][j] = dp[i-1][j]
 *            = 2   , dp[i][j] = dp[i][j-1]
 * 遍历 mark 时：
 * 若 mark[i][j] == 0，说明 s1[i-1] 和 s2[j-1] 被选入了最长公共子序列，需要记录下来
 * 若 dp[i][j] == 0，说明最长公共子序列的全部元素都已找到，停止遍历
 */

#include <vector>

using std::string;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        std::vector dp = std::vector(m + 1, std::vector(n + 1, 0));
        std::vector mark = std::vector(m + 1, std::vector(n + 1, 0));

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    mark[i][j] = 0;
                } else {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                    mark[i][j] = (dp[i][j - 1] > dp[i - 1][j]) + 1;
                }
            }
        }

        std::vector<std::pair<int, int>> idx_list{};
        {
            int i = m, j = n;
            while (dp[i][j] > 0) {
                switch (mark[i][j]) {
                    case 0:
                        idx_list.emplace_back(i - 1, j - 1);
                        --i, --j;
                        break;
                    case 1:
                        --i;
                        break;
                    case 2:
                        --j;
                        break;
                }
            }
        }
        reverse(idx_list.begin(), idx_list.end());

        string ans;
        {
            int i = 0, j = 0;
            for (const auto &each: idx_list) {
                ans += str1.substr(i, each.first - i);
                i = each.first + 1;
                ans += str2.substr(j, each.second - j);
                j = each.second + 1;
                ans += str1[each.first];
            }
            if (i < str1.size()) {
                ans += str1.substr(i);
            }
            if (j < str2.size()) {
                ans += str2.substr(j);
            }
        }
        return ans;
    }
};

#endif //LEETCODE_1092_H
