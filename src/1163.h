#ifndef LEETCODE_1163_H
#define LEETCODE_1163_H

/**
 * 假设 s(i) 为 s 中索引为 [i, n-1] 的子串，则最终答案一定在 s(0) ～ s(n-1) 中
 *
 * 假设 s(i) 为当前字典序最大的子串，s(j) 为待比较子串
 * 当前待比较的是子串中第 k 位，即比较 s[i+k] 和 s[j+k]，s 索引为 [i, i+k) 和 [j, j+k) 的子串都是一样的
 *
 * 若 s[i+k] == s[j+k]，说明两个子串字典序相同，继续比较：++k
 *
 * 若 s[i+k] < s[j+k]，此时找到了两个子串中第一个不同的字符，说明 s(i) < s(j)。
 * 此外，由于 s(i+k) 与 s(j+k) 的前缀相同，因此还能得出 s(i+p) < s(j+p)，0 <= p <= k
 * 即 s(i) ～ s(i+k) 都不可能是字典序最大的子串了，因此 i = max(j, i+k+1)，j = i+1
 *
 * 若 s[i+k] > s[j+k]，说明 s(i+p) > s(j+p)，0 <= p <= k
 * 即 s(j) ~ s(j+k) 都不可能是字典序最大的子串了，因此 j = j+k+1
 */

using std::string;

class Solution {
public:
    string lastSubstring(string s) {
        int n = static_cast<int>(s.size());
        int i = 0, j = 1, k = 0;
        while (j + k < n) {
            if (s[i + k] == s[j + k]) {
                ++k;
            } else if (s[i + k] < s[j + k]) {
                i = std::max(j, i + k + 1);
                j = i + 1;
                k = 0;
            } else {
                j = j + k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};

#endif //LEETCODE_1163_H
