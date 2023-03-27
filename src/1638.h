#ifndef LEETCODE_1638_H
#define LEETCODE_1638_H

using std::string;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            ans += total_count(s.substr(i), t);
        }
        for (int i = 1; i < t.size(); ++i) {
            ans += total_count(s, t.substr(i));
        }
        return ans;
    }

    // a、b恰好相差一个字符的等偏移子串的数量，即子串的起始索引必须相同
    int total_count(const string &a, const string &b) {
        int num = 0;
        auto n = std::min(a.size(), b.size());

        // 上上个不相等字符的索引，上个不相等字符的索引
        int k0 = -1, k1 = -1;

        // 枚举右边界，对每个右边界，都要包含上一个不相等字符，且不包含上上个不相等字符
        // 即子串的左边界位于 (k0, k1] 中即可，共有 k1-k0 个
        for (int r = 0; r < n; ++r) {
            if (a[r] != b[r]) {
                k0 = k1;
                k1 = r;
            }
            num += k1 - k0;
        }
        return num;
    }
};

#endif //LEETCODE_1638_H
