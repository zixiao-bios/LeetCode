#ifndef LEETCODE_0680_H
#define LEETCODE_0680_H

using namespace std;

class Solution {
public:
    bool checkSubString(const string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                return checkSubString(s, l + 1, r) or checkSubString(s, l, r - 1);
            }
            ++l, --r;
        }
        return true;
    }
};

#endif //LEETCODE_0680_H
