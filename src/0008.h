#ifndef LEETCODE_0008_H
#define LEETCODE_0008_H

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;

        while (i < s.size()) {
            if (s[i] == ' ') {
                ++i;
            } else {
                break;
            }
        }

        if (i == s.size()) {
            return 0;
        }

        int symbol = 1;
        if (s[i] == '-') {
            symbol = -1;
            ++i;
        } else if (s[i] == '+') {
            ++i;
        }

        long long val = 0;
        while (i < s.size()) {
            int d = s[i++] - '0';
            if (d >= 0 and d <= 9) {
                // 是数字
                val *= 10;
                val += d * symbol;

                // 检查溢出
                if (val < INT_MIN) {
                    return INT_MIN;
                } else if (val > INT_MAX) {
                    return INT_MAX;
                }
            } else {
                // 不是数字
                return val;
            }
        }

        return val;
    }
};

#endif //LEETCODE_0008_H
