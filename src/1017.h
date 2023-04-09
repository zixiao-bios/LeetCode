#ifndef LEETCODE_1017_H
#define LEETCODE_1017_H

#include <algorithm>

class Solution {
public:
    std::string baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }

        std::string ans;
        while (n != 0) {
            // 如果 n 是偶数，-2进制最低位为0
            bool d = (n % 2 != 0);
            ans += static_cast<char>('0' + d);
            n -= d;
            n /= -2;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODE_1017_H
