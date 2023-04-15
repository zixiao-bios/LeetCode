#ifndef LEETCODE_1023_H
#define LEETCODE_1023_H

#include <vector>

using std::vector, std::string;

class Solution {
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern) {
        vector<bool> ans;
        for (const auto &query: queries) {
            ans.push_back(match(query, pattern));
        }
        return ans;
    }

    bool match(const string &query, const string &pattern) {
        int p = 0;
        for (const auto &ch: query) {
            if (p < pattern.size() and ch == pattern[p]) {
                ++p;
            } else if (ch >= 'A' and ch <= 'Z') {
                return false;
            }
        }
        return p == pattern.size();
    }
};

#endif //LEETCODE_1023_H
