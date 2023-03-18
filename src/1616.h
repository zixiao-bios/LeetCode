#ifndef LEETCODE_1616_H
#define LEETCODE_1616_H

using std::string;

class Solution {
public:
    // 检查字符串的 [l, r] 子串是否为回文
    static bool is_huiwen(const string &s, int l, int r) {
        for (; l < r; ++l, --r) {
            if (s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }

    // 检查从某 idx 分割后，pre 的前缀和 suf 的后缀能否拼成回文
    bool check_xfix_huiwen(const string &pre, const string &suf) {
        // 先从两头分别检查最长的回文串
        int l = 0, r = suf.size() - 1;
        for (; l <= r and pre[l] == suf[r]; ++l, --r);
        return is_huiwen(pre, l, r) or is_huiwen(suf, l, r);
    }

    bool checkPalindromeFormation(string a, string b) {
        return check_xfix_huiwen(a, b) or check_xfix_huiwen(b, a);
    }
};

#endif //LEETCODE_1616_H
