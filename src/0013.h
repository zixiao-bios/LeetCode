#ifndef LEETCODE_0013_H
#define LEETCODE_0013_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, int> map = {{"I",  1},
                                      {"V",  5},
                                      {"X",  10},
                                      {"L",  50},
                                      {"C",  100},
                                      {"D",  500},
                                      {"M",  1000},
                                      {"IV", 4},
                                      {"IX", 9},
                                      {"XL", 40},
                                      {"XC", 90},
                                      {"CD", 400},
                                      {"CM", 900}};

    int romanToInt(string s) {
        int n = s.size();
        int p = 0, ans = 0;

        while (p < n) {
            if (n - p > 1 and map.find(s.substr(p, 2)) != map.end()) {
                // 特殊字符
                ans += map.at(s.substr(p, 2));
                p += 2;
            } else {
                // 单个字符
                ans += map.at(s.substr(p, 1));
                p += 1;
            }
        }

        return ans;
    }
};

#endif //LEETCODE_0013_H
