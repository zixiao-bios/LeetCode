#ifndef LEETCODE_0680_H
#define LEETCODE_0680_H

using namespace std;

class Solution {
public:
    bool check(const string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return check(s, left + 1, right) or check(s, left, right - 1);
            }
            ++left, --right;
        }

        return true;
    }
};

#endif //LEETCODE_0680_H
