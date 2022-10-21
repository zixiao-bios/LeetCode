#ifndef LEETCODE_0139_H
#define LEETCODE_0139_H

#include <vector>
#include <unordered_set>

using namespace std;

/**
 * dp[i]: s 的前 i 个字符组成的字符串是否合法
 *
 * dp[i] = dp[j] and check(s[j:i-1])
 *
 * dp[0] = true
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (const auto &str: wordDict) {
            dict.insert(str);
        }

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] and dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

#endif //LEETCODE_0139_H
