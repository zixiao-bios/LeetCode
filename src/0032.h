#ifndef LEETCODE_0032_H
#define LEETCODE_0032_H

/**
 * dp[i]: 以索引为 i 的元素结尾的最长括号序列长度
 *
 */

#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);

        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
                } else if (dp[i - 1] < i and s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = i - dp[i - 1] - 2 >= 0 ? dp[i - 1] + dp[i - dp[i - 1] - 2] + 2 : dp[i - 1] + 2;
                }
            }
        }

        int ans = 0;
        for (auto &each: dp) {
            ans = max(ans, each);
        }

        return ans;
    }
};

#endif //LEETCODE_0032_H
