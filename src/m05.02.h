#ifndef LEETCODE_M05_02_H
#define LEETCODE_M05_02_H

class Solution {
public:
    std::string printBin(double num) {
        std::string ans = "0.";
        while (num != 0 and ans.size() <= 32) {
            num *= 2;
            ans += char(int(num) + '0');
            num -= int(num);
        }

        if (ans.size() > 32) {
            return "ERROR";
        } else {
            return ans;
        }
    }
};

#endif //LEETCODE_M05_02_H
