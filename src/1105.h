#ifndef LEETCODE_1105_H
#define LEETCODE_1105_H

/**
 * dp[i]: 只考虑 books 前 i 本书，此时总的最小高度
 *
 * 假设最后一层放的书为 lb，其长度为 j，索引范围为 [i-j, i-1]
 * dp[i] = min( dp[i-j] + max(lbh) )  , 1 <= j <= i, lbw <= w
 *
 * dp[0] = 0
 */

#include <vector>

using std::vector;

class Solution {
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
        int n = static_cast<int>(books.size());
        vector<int32_t> dp(n + 1, INT32_MAX);
        dp[0] = 0;

        for (int i = 1; i < n + 1; ++i) {
            int max_h = 0, width = 0;
            for (int j = 1; j <= i; ++j) {
                max_h = std::max(max_h, books[i - j][1]);
                width += books[i - j][0];
                if (width <= shelfWidth) {
                    dp[i] = std::min(dp[i], dp[i - j] + max_h);
                } else {
                    break;
                }
            }
        }
        return dp[n];
    }
};

#endif //LEETCODE_1105_H
