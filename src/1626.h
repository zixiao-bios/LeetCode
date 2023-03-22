#ifndef LEETCODE_1626_H
#define LEETCODE_1626_H

/**
 * 首先按主序为 age 升序，次序为 score 升序，将 scores 和 age 排序
 *
 * dp[i]: 在索引为 [0, i] 的队员中选择，且选择索引为 i 的队员时，球队的最大得分
 *
 * 根据排序规则，对于 dp[i] 选定的球队，i 号球员年龄 >= 其他球员，得分 >= 其他球员
 *
 * dp[i] = max(dp[j]) + scores[i]   , 0 <= j < i, (age[i] > age[j] and scores[i] >= scores[j]) or (age[i] == age[j])
 *                                  , 上述条件化简为 scores[i] >= scores[j]
 *       = scores[i]                , 不存在满足上式的 j
 *
 * dp[0] = scores[0]
 */

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        auto n = scores.size();
        vector<std::pair<int, int>> data;
        for (int i = 0; i < n; ++i) {
            data.emplace_back(ages[i], scores[i]);
        }

        std::sort(data.begin(), data.end());

        vector<int> dp(n);
        dp[0] = data[0].second;
        for (int i = 1; i < n; ++i) {
            int max_score = -1;
            for (int j = 0; j < i; ++j) {
                if (data[i].second >= data[j].second) {
                    max_score = std::max(max_score, dp[j]);
                }
            }
            if (max_score == -1) {
                dp[i] = data[i].second;
            } else {
                dp[i] = max_score + data[i].second;
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};

#endif //LEETCODE_1626_H
