#ifndef LEETCODE_0058_H
#define LEETCODE_0058_H

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int right = s.size() - 1;
        while (s[right] == ' ') {
            --right;
        }

        int left = right;
        while (left > 0 and s[left] != ' ') {
            --left;
        }
        if (s[left] == ' ') {
            ++left;
        }

        return right - left + 1;
    }
};

#endif //LEETCODE_0058_H
