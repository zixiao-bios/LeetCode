#ifndef LEETCODE_2399_H
#define LEETCODE_2399_H

#include <vector>
#include <unordered_map>

using std::vector, std::string;

class Solution {
public:
    bool checkDistances(string s, vector<int> &distance) {
        std::unordered_map<char, int> pre_idx;
        for (int i = 0; i < s.size(); ++i) {
            if (pre_idx.find(s[i]) == pre_idx.end()) {
                pre_idx[s[i]] = i;
            } else {
                if (i - pre_idx[s[i]] - 1 != distance[s[i] - 'a']) {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif //LEETCODE_2399_H
