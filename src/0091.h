#ifndef LEETCODE_0091_H
#define LEETCODE_0091_H

#include <vector>

using namespace std;

/**
 * dp[i]: 索引在 [0,i] 中的字符的解码方法数量
 *
 * 设 k 为 s[i] 和 s[i-1] 组成的数字
 * if (不能和前一位组合，也不能独立)
 *      无法解码
 * else if (只能和前一位组合)
 *      dp[i] = dp[i-2]
 * else if (只能独立)
 *      dp[i] = dp[i-1]
 * else
 *      dp[i] = dp[i-1] + dp[i-2]
 */

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) {
            return 0;
        }

        for (auto &ch:s) {
            if (ch == '-') {
                return 0;
            }
        }

        if (s[0] == '0') {
            return 0;
        }

        if (s.size() == 1) {
            return 1;
        }

        vector<int> dp(s.size(), -1);
        dp[0] = 1;
        int prev = char2int(s[0]), cur = char2int(s[1]);
        if (!canCombineOne(cur) and !canCombineTwo(prev, cur)) {
            return 0;
        } else if (canCombineOne(cur) and canCombineTwo(prev, cur)) {
            dp[1] = 2;
        } else {
            dp[1] = 1;
        }

        prev = cur;
        for (int i = 2; i < s.size(); ++i) {
            cur = char2int(s[i]);
            if (!canCombineOne(cur) and !canCombineTwo(prev, cur)) {
                return 0;
            } else if (!canCombineOne(cur) and canCombineTwo(prev, cur)) {
                // 只能和前一位组合
                dp[i] = dp[i - 2];
            } else if (canCombineOne(cur) and !canCombineTwo(prev, cur)) {
                // 只能自己单独
                dp[i] = dp[i - 1];
            } else {
                // 可以和前一位组合，也可以单独
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            prev = cur;
        }

        return dp[s.size() - 1];
    }

    int char2int(char ch) {
        return ch - '0';
    }

    bool canCombineTwo(int prev, int cur) {
        int k = prev * 10 + cur;
        return k < 27 and k > 9;
    }

    bool canCombineOne(int cur) {
        return cur != 0;
    }
};

#endif //LEETCODE_0091_H
