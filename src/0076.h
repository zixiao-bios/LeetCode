#ifndef LEETCODE_0076_H
#define LEETCODE_0076_H

#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> target, source;

    bool check() {
        for (auto &each: target) {
            if (source[each.first] < each.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (auto &ch: t) {
            ++target[ch];
        }

        int min_len = INT_MAX, left = 0, min_left = -1;
        for (int right = 0; right < s.size(); ++right) {
            ++source[s[right]];

            while (check()) {
                int len = right - left + 1;
                if (len < min_len) {
                    min_len = len;
                    min_left = left;
                }
                --source[s[left]];
                ++left;
            }
        }

        return min_left == -1 ? "" : s.substr(min_left, min_len);
    }
};

#endif //LEETCODE_0076_H
