#ifndef LEETCODE_0650_H
#define LEETCODE_0650_H

#include <vector>

using namespace std;

/**
 * dp[i]: 生成 i 个 A 所需的最小步数
 */

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, -1);

        dp[1] = 0;

        for (int i = 2; i < n + 1; ++i) {
            for (int j = i - 1; j >= 1; --j) {
                if (i % j == 0) {
                    dp[i] = dp[j] + i / j;
                    break;
                }
            }
        }

        return dp[n];
    }
};

#endif //LEETCODE_0650_H
