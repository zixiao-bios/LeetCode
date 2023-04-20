#ifndef LEETCODE_1187_H
#define LEETCODE_1187_H

/**
 * dp[i][j]: a 的前 i 个元素中，进行 j 次替换后，该子序列严格递增，且 a[i-1] 能达到的最小值
 *
 * dp[i][j] =
 *      1. 保留 a[i-1]: dp[i][j] = a[i-1]     , j < i and a[i-1] > dp[i-1][j]
 *      2. 替换 a[i-1]: dp[i][j] = b[k]       , j > 0 and b[k] > dp[i-1][j-1] 且 b[k] 尽可能小
 *
 * dp[0][0] = -1
 */

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
        std::sort(arr2.begin(), arr2.end());
        arr2.erase(std::unique(arr2.begin(), arr2.end()), arr2.end());
        int n = arr1.size();
        int j_n = std::min(arr1.size(), arr2.size());
        vector<vector<int32_t>> dp = vector(n + 1, vector(j_n + 1, INT32_MAX));

        dp[0][0] = -1;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j <= std::min(i, j_n); ++j) {
                if (j < i and arr1[i - 1] > dp[i - 1][j]) {
                    dp[i][j] = arr1[i - 1];
                }

                if (j > 0 and dp[i - 1][j - 1] != INT32_MAX) {
                    auto it = std::upper_bound(arr2.begin() + j - 1, arr2.end(), dp[i - 1][j - 1]);
                    if (it != arr2.end()) {
                        dp[i][j] = std::min(dp[i][j], *it);
                    }
                }

                if (i == n and dp[i][j] != INT32_MAX) {
                    return j;
                }
            }
        }
        return -1;
    }
};

#endif //LEETCODE_1187_H
