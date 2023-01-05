#ifndef LEETCODE_0012_H
#define LEETCODE_0012_H

#include <map>

using namespace std;

class Solution {
public:
    map<int, string> map = {{1000, "M"},
                            {900,  "CM"},
                            {500,  "D"},
                            {400,  "CD"},
                            {100,  "C"},
                            {90,   "XC"},
                            {50,   "L"},
                            {40,   "XL"},
                            {10,   "X"},
                            {9,    "IX"},
                            {5,    "V"},
                            {4,    "IV"},
                            {1,    "I"}};

    string intToRoman(int num) {
        string ans;
        auto it = map.rbegin();

        while (num != 0) {
            if (num - it->first >= 0) {
                num -= it->first;
                ans += it->second;
            } else {
                ++it;
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0012_H
