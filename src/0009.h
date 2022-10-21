#ifndef LEETCODE_0009_H
#define LEETCODE_0009_H

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 or (x != 0 and x % 10 == 0)) {
            return false;
        }

        int reverse = 0;
        while (reverse < x) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }

        return reverse == x or reverse / 10 == x;
    }
};

#endif //LEETCODE_0009_H
