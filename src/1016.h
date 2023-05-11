#ifndef LEETCODE_1016_H
#define LEETCODE_1016_H

#include <unordered_set>

class Solution {
public:
    bool queryString(std::string s, int n) {
        std::unordered_set<int> set;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                continue;
            }

            int x = 1;
            set.insert(x);
            for (int j = i + 1; j < s.size(); ++j) {
                x <<= 1;
                x |= s[j] - '0';
                if (x <= n) {
                    set.insert(x);
                } else {
                    break;
                }
            }
        }

        return set.size() == n;
    }
};

#endif //LEETCODE_1016_H
