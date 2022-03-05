#ifndef LEETCODE_0474_H
#define LEETCODE_0474_H

#include <vector>

using namespace std;

/**
 * dp[i][j][k]: 在前 i 个元素中，最多有 j 个 0 和 k 个 1 的最大子集长度
 */

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        int n0, n1;

        for (int i = 1; i < strs.size() + 1; ++i) {
            n0 = numsOf(strs[i - 1], 0);
            n1 = numsOf(strs[i - 1], 1);

            for (int j = m; j >= n0; --j) {
                for (int k = n; k >= n1; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - n0][k - n1] + 1);
                }
            }
        }

        return dp[m][n];
    }

    int numsOf(const string &str, int x) {
        int ans = 0;
        for (auto &each:str) {
            if (x + '0' == each) {
                ++ans;
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0474_H
