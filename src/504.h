#ifndef LEETCODE_504_H
#define LEETCODE_504_H

class Solution {
public:
    std::string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }

        std::string ans;
        bool neg = false;
        if (num < 0) {
            neg = true;
            num = -num;
        }

        while (num != 0) {
            int d = num % 7;
            ans += static_cast<char>(d + '0');
            num -= d;
            num /= 7;
        }
        if (neg) {
            ans += '-';
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODE_504_H
